#include <stdio.h>
#include <string.h>
char in[ 100010 ];
int res[ 100010 ], Q;
int main()
{
    gets( in );
    int a, b, len = strlen( in ) - 1;
    res[ 0 ] = res[len - 1] = 0;
    for(int i = 0; i < len; i++) res[ i ] = in[ i ] == in[i + 1] ? 1 : 0;
    for(int i = 0; i < len; i++) res[ i ] = res[ i ] + res[i - 1];
    //for(int i = 0; i < len; i++) printf("%d ", res[ i ]); puts("");
    scanf("%d", &Q);
    while( Q-- )
    {
        scanf("%d %d", &a, &b); a--; b -= 2;
        printf("%d\n", res[ b ] - res[a - 1]);
    }
    return 0;
}
