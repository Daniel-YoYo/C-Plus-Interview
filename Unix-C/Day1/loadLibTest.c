#include <stdio.h>
#include "features.h"

int main()  
{
    int a = 10, b = 2;

    // Call function interface
    printf("%d+%d=%d\n", a, b, addNum( a, b ) );
    printf("%d-%d=%d\n", a, b, subNum( a, b ) );
    printf("%d*%d=%d\n", a, b, mulNum( a, b ) );
    printf("%d/%d=%d\n", a, b, divNum( a, b ) );

    return 0;
}