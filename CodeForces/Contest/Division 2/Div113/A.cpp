#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct data
{
    int sp, tt;
}in[ 55 ];

bool cmp(const data &x, const data &y)
{
    if(x.sp > y.sp) return true;
    if(x.sp == y.sp && x.tt < y.tt) return true;
    return false;
};

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d %d", &in[i].sp, &in[i].tt);
    sort(in, in + n, cmp);

    //for(int i = 0; i < n; i++) printf("%d %d\n", in[i].sp, in[i].tt);

    int a = in[k - 1].sp, b = in[k - 1].tt;
    int res = 1, p = k - 2;

    while(p > -1 && in[p].sp == a && in[p].tt == b) p--, res++; p = k;
    while(p < n && in[p].sp == a && in[p].tt == b) p++, res++;

    printf("%d\n", res);
}
