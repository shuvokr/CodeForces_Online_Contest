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
void input();
bool ok(long long a, long long b, long long c);
long long x11, y11, x22, y22;

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    cin >> x11 >> y11 >> x22 >> y22;
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if(ok(a, b, c)) res++;
    }
     cout << res << endl;
}
bool ok(long long a, long long b, long long c)
{
    long long x = a * x11 + b * y11 + c;
    long long y = a * x22 + b * y22 + c;
    //cout << x << " " << y << endl;
    return !((x < 0 && y < 0) || (x > 0 && y > 0));
}
