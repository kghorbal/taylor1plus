#include "itv.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
	itv_t itv,bot,top;
    num_t a,b;

    num_init(a);
    num_init(b);
    num_set_int(a,-6469);
    num_set_int(b,-1121);

    itv_init(itv);
    itv_init(bot);
    itv_init(top);

    itv_set_bottom(bot);
    itv_set_num2(itv,a,b);
    itv_set_top(top);

    assert(itv_is_leq(bot,top));
    assert(itv_is_leq(top,top));
    assert(itv_is_leq(bot,bot));
    assert(!itv_is_leq(top,bot));
    assert(itv_is_leq(itv,top));
    assert(itv_is_leq(bot,itv));
    //printf("top <= top? %d \n",itv_is_leq(top,top));
	return 0;
}

// gcc -DNUM_MPZ -I./apron -I./num -I./itv -L./apron -lgmp -lmpfr -o testitv apron/libapron.a taylor1plus/tests/test_itv_is_leq.c 
