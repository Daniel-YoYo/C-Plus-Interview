#include <unistd.h>
#include <stdio.h>

extern char **__environ;

int main()
{
    for( int i = 0; __environ[i] != NULL; i++ )
    {
        printf("%s\n", __environ[i] );
    }

    return 0;

}