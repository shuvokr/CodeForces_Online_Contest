#include <stdio.h>
#include <algorithm>

using namespace std;

struct data
{
    int ind;
}a[ 5010 ], b[ 5010 ], c[ 5010 ];

int main()
{
    int n, aa = 0, bb = 0, cc = 0;
    scanf("%d", &n);
    for(int tmp, i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 1) a[ aa++ ].ind = i;
        else if(tmp == 2) b[ bb++ ].ind = i;
        else c[ cc++ ].ind = i;
    }

    int mx = min(aa, min(bb, cc));
    printf("%d\n", mx);
    for(int i = 0; i < mx; i++)
    {
        printf("%d %d %d\n", a[i].ind, b[i].ind, c[i].ind);
    }
    return 0;
}
