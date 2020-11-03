#include <stdio.h>
#include <string.h>

int main()
{
    char buf[10];
    // error: assignment to expression with array type
    // buf = "Hello";   

    char buf1[10];
    strcpy( buf1, "Hello");

    char buf2[10] = "Hello";

    char buf3[10] = {'H', 'e', 'l', 'l', 'o' };

    printf("%s\n", buf );
    printf("%s\n", buf1 );
    printf("%s\n", buf2 );
    printf("%s\n", buf3 );

    return 0;
}