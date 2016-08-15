#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int pos, int pos2);

int n, m, in[ 55 ], mamo[ 55 ][ 55 ];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &in[ i ]);
    sort(in, in + m);
    memset(mamo, -1, sizeof mamo);
    printf("%d\n", DP(0, n - 1));
    return 0;
}
int DP(int pos, int pos2)
{
    if(pos2 == m) return 1000000000;
    int &ret = mamo[ pos ][ pos2 ];
    if(ret != -1) return ret;

    return ret = min(in[ pos2 ] - in[ pos ], DP(pos + 1, pos2 + 1));
}
