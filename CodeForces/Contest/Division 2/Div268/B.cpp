#include <stdio.h>
#include <string.h>
int main()
{
    int p, q, l, r, a, b, x[ 55 ], y[ 55 ];
    scanf("%d %d %d %d", &p, &q, &l, &r);
    bool mark[ 2010 ];
    memset(mark, false, sizeof mark);
    for(int i = 0; i < p; i++)
    {
        scanf("%d %d", &a, &b);
        for(int j = a; j <= b; j++) mark[ j ] = true;
    }
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        x[ i ] = a; y[ i ] = b;
    }

    int cou = 0;
    for(int i = l; i <= r; i++)
        for(int k = 0; k < q; k++)
            for(int j = x[ k ] + i; j <= y[ k ] + i; j++)
                if(mark[ j ])
                {
                    cou++;
                    k = q + 10;
                    break;
                }

    printf("%d\n", cou);
    return 0;
}
