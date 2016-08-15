#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

long long DP(int pos, int flag);

long long mamo[ 100010 ][ 2 ];
long long n, in[ 100010 ], val[ 100010 ];

int main()
{
    cin >> n; memset(val, 0, sizeof val);
    for(int i = 0; i < n; i++)
    {
        cin >> in[ i ];
        val[ in[ i ] ]++;
    }
    for(int i = 1; i < 100001; i++) val[ i ] *= i;
    memset(mamo, -1, sizeof mamo);
    cout << DP(1, 0) << endl;
    return 0;
}
long long DP(int pos, int flag)
{
    //cout << pos << " ";
    if(pos > 100000) return 0ll;
    long long &ret = mamo[ pos ][ flag ];
    if(ret != -1) return ret;

    if(flag)
    {
        ret = DP(pos + 1, 0);
    }
    else
    {
        ret = max(DP(pos + 1, 1) + val[ pos ], DP(pos + 1, 0));
    }
    return ret;
}
