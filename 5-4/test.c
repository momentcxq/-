# include "my-malloc.h"
void main(void)
{
    /* print_list(); */
    char *p[200] ;
    int i;

    for (i = 0; i < 20; i++) {
        p[i] = (char *) Malloc(8) ;
        printf("malloc %d, %X\n", i, p[i] ) ;
        print_list() ;
    }

    for (i = 19; i >= 0; i - -) {
        Free( p[i] ) ;
        printf("free %d \n" , i) ;
        print_list() ;
    }
}
