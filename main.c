#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "Fun.h"

int main() {
    setbuf(stdout, 0);
    srand(time(NULL));
    struct cinema *c_list=NULL;
    int kol_vo=0;
    printf("Vvedi kolichestvo struktur \n");
    scanf_s("%d",&kol_vo);
    c_list=generate(c_list,kol_vo);
    print_list(c_list,kol_vo);
    print_str(find_with_interface(c_list,kol_vo));
    //print_list(c_list,kol_vo);
    return 0;
}
