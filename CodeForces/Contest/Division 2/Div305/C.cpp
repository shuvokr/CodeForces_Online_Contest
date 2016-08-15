/***************** Shuvo *****************/
/****************** DIU *****************/

#pragma comment(linker, "/stack:64000000")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>

using namespace std;
void  input();

long long mod, h1, a1, x1, h2, a2, x2, y2, y11;

int main()
{
    #ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void input()
{
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",
       &mod, &h1, &a1, &x1, &y11, &h2, &a2, &x2, &y2);

    int cou = 0; long long sum = h1;
    while( cou < mod )
    {
        if(sum == a1) break;
        sum = (((x1*sum) % mod) + y11) % mod;
        cou++;
    }

    int cou1 = 0; sum = h2;
    while( cou1 < mod )
    {
        if(sum == a2) break;
        sum = (((x2*sum) % mod) + y2) % mod;
        cou1++;
    }

    if(cou == mod || cou1 == mod)
    {
        puts("-1");
        return;
    }

    long long mn = min(cou, cou1), mx = max(cou, cou1), s = mx, ss = 1000000000001ll;

    cout << mx << " " << mn << endl;

    long long ans = -1;
    while(mx <= ss)
    {
        long long t = mx / mn;
        if(mn * t == mx)
        {
            ans = mx;
            break;
        }
        mx += s;
    }

    cout << ans << endl;
}
