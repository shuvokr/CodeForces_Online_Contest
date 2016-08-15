#include <stdio.h>
#include <string.h>

template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
struct stree
{
    int gd, cou;
}tree[4 * 100005], ans;

void init(int node, int b, int e);
void marge(stree &p, stree &l, stree &r);
stree query(int node, int b, int e, int ll, int hh);

int in[ 100005 ], n, q, low, high;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &in[ i ]);
    init(1, 1, n);
    scanf("%d", &q);
    while( q-- )
    {
        scanf("%d %d", &low, &high);
        ans = query(1, 1, n, low, high);
        printf("%d\n",1 + high - low - ans.cou);
    }
    return 0;
}
void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[ node ].gd = in[ b ];
        tree[ node ].cou = 1;
        return;
    }
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;
    init(left, b, mid); init(right, mid + 1, e);
    marge(tree[ node ], tree[ left ], tree[ right ]);
}
void marge(stree &p, stree &l, stree &r)
{
    p.gd = gcd(l.gd, r.gd); p.cou = 0;
    if(!(p.gd % l.gd)) p.cou += l.cou;
    if(!(p.gd % r.gd)) p.cou += r.cou;
}
stree query(int node, int b, int e, int ll, int hh)
{
    if(b == ll && e == hh) return tree[ node ];
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    if(hh <= mid) return query(left, b, mid, ll, hh);
    if(ll > mid) return query(right, mid + 1, e, ll, hh);

    stree ret, retl, retr;

    retl = query(left, b, mid, ll, mid);
    retr = query(right, mid + 1, e, mid+1, hh);

    ret.gd = gcd(retl.gd, retr.gd); ret.cou = 0;

    if(!(ret.gd % retl.gd)) ret.cou += retl.cou;
    if(!(ret.gd % retr.gd)) ret.cou += retr.cou;

    return ret;
}
