#include <stdlib.h>
#include <stdio.h>


int     main()
{
    char *a = malloc(4);
    a[0] = 'h';
    a[1] = 'i';
    a[2] = '!';
    a[3] = 0;



    char *b = a + 5;
    //*b = 'c';

    printf("%s\n", a);
    return 0;
}
