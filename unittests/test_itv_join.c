#include "itv.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
	itv_t itv,bot,res;
    num_t a,b;

    num_init(a);
    num_init(b);
    num_set_int(a,-6469);
    num_set_int(b,-1121);

    itv_init(bot);
    itv_init(itv);
    itv_init(res);

    itv_set_bottom(bot);
    itv_set_num2(itv,a,b);

    itv_join(res,bot,itv);

    itv_fprint(stdout,bot);
    printf(" U ");
    itv_fprint(stdout,itv);
    printf(" = ");
    itv_fprint(stdout,res);
    printf("\n");

	return 0;
}
