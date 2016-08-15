#include <stdio.h>
#include <string.h>
int main()
{
    int num, n, q;
    bool mark[ 101 ];
    memset(mark, false, sizeof mark);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) mark[ i ] = true;
    scanf("%d", &q);
    while( q-- )
    {
        scanf("%d", &num);
        mark[ num ] = false;
    }
    scanf("%d", &q);
    while( q-- )
    {
        scanf("%d", &num);
        mark[ num ] = false;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mark[ i ])
        {
            puts("Oh, my keyboard!");
            return 0;
        }
    }
    puts("I become the guy.");
    return 0;
}
