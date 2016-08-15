#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int DP(int cut);
int mamo[ 10010 ];
int a, b, c, n;
int main()
{
    scanf("%d %d %d %d", &n, &a, &b, &c);
    memset(mamo, -1, sizeof mamo);
    printf("%d\n", DP( n ) - 1);
    return 0;
}
int DP(int cut)
{
    if(cut == 0) return 1;
    if(cut < 0) return -1000000000;
    int &ret = mamo[ cut ];

    if(ret != -1) return ret;
    ret = max( 1 + DP(cut - a), max( 1 + DP(cut - b), 1 + DP(cut - c) ) );
    return ret;
}
