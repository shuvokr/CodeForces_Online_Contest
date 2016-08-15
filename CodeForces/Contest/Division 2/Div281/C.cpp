#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int a[ 200010 ], b[ 200010 ], n, m;
    while(~scanf("%d", &n)){
    for(int i = 1; i <= n; i++) scanf("%d", &a[ i ]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", &b[ i ]);

    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);

    long long x, y, dif = -200000000000010;
    for(int i = 1; i <= n; i++)
    {
        int k = i;
        while(a[ k ] == a[ i ] && k <= n) k++;
        k--; int d = a[ k ];
        i = k;

        if(i + 1 <= n) d = a[i + 1] - 1;

        int high = m, low = 1, mid;
        while(high - low > 1)
        {
            mid = (low + high) >> 1;
            if(b[ mid ] > d) high = mid - 1;
            else low = mid;
        }

        while(b[ high ] > d && high > 0) high--;

        long long yy = high * 2 + (m - high) * 3;
        long long xx = i * 2 + (n - i) * 3;
        if(xx - yy > dif)
        {
            dif = xx - yy;
            x = xx; y = yy;
        }
        else if(xx - yy == dif && x < xx) x = xx, y = yy;
    }

    int d = a[ 1 ] - 1;
    int high = m, low = 1, mid;
    while(high - low > 1)
    {
        mid = (low + high) >> 1;
        if(b[ mid ] > d) high = mid - 1;
        else low = mid;
    }
    while(b[ high ] > d && high > 0) high--;
    //cout << high << " " << b[ high ] << " " << d << endl;

    long long yy = high * 2 + (m - high) * 3;
    long long xx = n * 3;

    if(xx - yy > dif) {x = xx, y = yy; dif = xx - yy;}
    else if(xx - yy == dif && x < xx) x = xx, y = yy;

    yy = m * 2;
    xx = n * 2;
    //cout << xx << " " << yy << " " << dif << endl;
    if(xx - yy > dif) x = xx, y = yy;
    else if(xx - yy == dif && x < xx) x = xx, y = yy;

    printf("%I64d:%I64d\n", x, y);
    }
    return 0;
}
