#include <stdio.h>
#include <string.h>

int DP(int cost, int flag);

int N, K, D, mamo[ 110 ][ 2 ], mod = 1000000007;

int main()
{
    while(~scanf("%d %d %d", &N, &K, &D))
    {
        memset(mamo, -1, sizeof mamo);
        printf("%d\n", DP(N, 0) % mod);
    }
}
int DP(int cost, int flag)
{
    if(cost == 0) return flag;
    if(cost < 0) return 0;
    int &ret = mamo[ cost ][ flag ];
    if(ret != -1) return ret;
    int way = 0;
    for(int i = 1; i <= K; i++)
    {
        if(flag == 1) way = (way + DP(cost - i, 1)) % mod;
        else if(i >= D) way = (way + DP(cost - i, 1)) % mod;
        else way = (way + DP(cost - i, 0)) % mod;
    }
    return ret = way % mod;
}
