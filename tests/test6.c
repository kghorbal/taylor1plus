#include <time.h>
#include "t1p.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {

    ap_manager_t* man = t1p_manager_alloc();

    ap_abstract0_t* bot = ap_abstract0_bottom(man, 2, 0);
    printf("bottom:\n");
    ap_abstract0_fprint(stdout, man, bot, NULL);

    ap_dim_t * tdim = (ap_dim_t *) malloc(sizeof(ap_dim_t));
    tdim[0] = 0;

    ap_abstract0_t* res = ap_abstract0_forget_array(man, false, bot,
            tdim, 1, false);
    printf("result:\n");
    ap_abstract0_fprint(stdout, man, res, NULL);

    //should be true
    if (ap_abstract0_is_leq(man, bot, res)==true) printf("test passed \n");
    else printf("test failed \n");

    return 0;
}
