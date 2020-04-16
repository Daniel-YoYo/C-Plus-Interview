#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

using namespace  std;

int main()
{
    int a = 10;
    int *p = &a;

    printf("%p\n",p );
    printf("%p\t%p\n",*p, &a );
    printf("%p\n", &p);

    return 0;
}