#include <time.h>
#include "t1p.h"
#include <string.h>
#include <stdio.h>

ap_abstract0_t * create_zonotope(ap_manager_t* man, int dim,
		double values[dim][2]) {
	ap_interval_t** intervals = ap_interval_array_alloc(dim);
	int i;
	for (i = 0; i < dim; i++) {
		ap_interval_set_double(intervals[i], values[i][0], values[i][1]);
	}
	ap_abstract0_t * zonotope = ap_abstract0_of_box(man, dim, 0, intervals);
	return zonotope;
}

int main(int argc, char **argv) {
	int dim = 2;

	ap_manager_t * man = t1p_manager_alloc();
	ap_abstract0_t* bottom = ap_abstract0_bottom(man, dim, 0);
	ap_abstract0_t* top = ap_abstract0_top(man, dim, 0);

	double values1[2][2] = { { 1, 1 }, { -6469, -1121 } };
	ap_abstract0_t* zonotope1 = create_zonotope(man, dim, values1);
	printf("zonotope1:\n");
	ap_abstract0_fprint(stdout, man, zonotope1, NULL);

	double values2[2][2] = { { 1, 1 }, { -4135, 3562 } };
	ap_abstract0_t* zonotope2 = create_zonotope(man, dim, values2);
	printf("zonotope2:\n");
	ap_abstract0_fprint(stdout, man, zonotope2, NULL);

	ap_dim_t * tdim = (ap_dim_t *) malloc(sizeof(ap_dim_t));
	tdim[0] = 1;

	ap_abstract0_t* zonotope3 = ap_abstract0_forget_array(man, false, zonotope2,
			tdim, 1, false);

	printf("zonotope3:\n");
	ap_abstract0_fprint(stdout, man, zonotope3, NULL);

	ap_abstract0_t* widening_result = ap_abstract0_widening(man, zonotope1,
			zonotope3);
	printf("widening result:\n");
	ap_abstract0_fprint(stdout, man, widening_result, NULL);

	//fails because zonotope3[0]->itv = [-oo,+oo] and widening_result[0]->c = [1, 1]
	printf("zonotope3 <= zonotope1 widening zonotope3: ");
	printf("%d\n", (ap_abstract0_is_leq(man, zonotope3, widening_result)));

	return 0;
}

// gcc -I./apron -I./taylor1plus -L./apron -L./taylor1plus -lgmp -lmpfr -o test29 ./apron/libapron.a ./box/libboxMPQ.a ./newpolka/libpolkaMPQ.a ./taylor1plus/libt1pMPQ.a taylor1plus/unittests/test29.c
