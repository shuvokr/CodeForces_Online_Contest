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

#define phl puts("Hello")
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define CLR(n, v) memset(n, v, sizeof( n ))
#define INF 1 << 30
#define pb push_back
#define lim(v) v.begin(), v.end()
#define sz(v) ((int)v,size())
#define equals(a, b) (fabs(a-b)<eps)

#define white 0
#define black 1

const double PI = 2 * acos ( 0.0 );
const double eps = 1e-9;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pi;
typedef  vector<int> vi;
typedef vector<pi> vpi;

template <class T> T jog(T a, T b) { return a + b; }
template <class T> T bog(T a, T b) { return a - b; }
template <class T> T gon(T a, T b) { return a * b; }
template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { return b == 0 ? a : gcd(b, a % b); }
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
template <class T> T cordinatlenth(T a, T b, T c, T d) { return sqrt( sq(a - c) + sq(b - d) ); }
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
lld bigmod ( lld a, lld p, lld mod )
{
    lld res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}

/*
#define M 1000005
int phi[M];

void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++)
        if (phi[p] == p) // p is a prime
            for (int k = p; k < M; k += p) phi[k] -= phi[k] / p;
}
*/

/*
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) ind++; printf("%d\n", ind);
}
*/

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

struct data
{
    int a, b;
}in[ 200005 ];

bool cmp1(const data &x, const data &y)
{
    return (x.a < y.a);
}

bool cmp2(const data &x, const data &y)
{
    return (x.b < y.b);
}

int n, ck[ 1000010 ];
vector <int> q1, q2;

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
    int f, s; CLR(ck, 0);
    cin >> n;
    bool mark[ 1000010 ];
    CLR(mark, false);
    q1.clear();
    q2.clear();
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &in[ i ].a, &in[ i ].b);
        ck[ in[ i ].b ]++;
        ck[ in[ i ].a ]++;
        if( !in[ i ].a ) {f = in[ i ].b; q1.pb( in[ i ].b ); in[ i ].b = 1000010; mark[ f ] = true;}
        if( !in[ i ].b && n % 2 == 0 ) {s = in[ i ].a; q2.pb( in[ i ].a ); in[ i ].a = 1000010; }
    }

    sort(in + 1, in + n + 1, cmp1);
    while( true )
    {
        int low = 1, high = n, mid;
        while(high - low > 1)
        {
            mid = (low + high) >> 1;
            if(in[ mid ].a > f) high = mid - 1;
            else low = mid;
        }

        if(in[high].a == f) low = high;

        if(in[ low ].a != f || !in[ low ].b || in[low].b == 1000010) break;
        else
        {
            q1.pb(in[ low ].b);
            f = in[ low ].b;
            mark[ f ] = true;
            in[ low ].b = 1000010;
        }
    }
    if(n % 2 == 0)
    {
        sort(in + 1, in + n + 1, cmp2);
        while( true )
        {
            int low = 1, high = n, mid;
            while(high - low > 1)
            {
                mid = (low + high) >> 1;
                if(in[ mid ].b > s) high = mid - 1;
                else low = mid;
            }

            if(in[high].b == s) low = high;

            if(in[ low ].b != s) break;
            else
            {
                q2.pb(in[ low ].a);
                s = in[ low ].a;
                in[ low ].a = 1000010;
            }
        }
    }
    else
    {
        sort(in + 1, in + n + 1, cmp2);
        int i;
        for(int j = 1; j <= n; j++)
        {
            if(mark[ in[j].b ] || in[j].b == 0 || in[j].b == 1000010) continue;
            if(ck[ in[j].b ] == 1)
            {
                //printf("%d\n", in[j].b);
                i = j;
                break;
            }
        }
            q2.clear();
            q2.pb(in[ i ].b);
            q2.pb(in[ i ].a);

            if(q1.size() + q2.size() != n)
            {
            s = in[ i ].a;

            while( true )
            {
                int low = 1, high = n, mid;
                while(high - low > 1)
                {
                    mid = (low + high) >> 1;
                    if(in[ mid ].b > s) high = mid - 1;
                    else low = mid;
                }
                if(in[ high ].b == s) low = high;
                if(in[ low ].b != s || in[ low ].b == 1000010) break;
                else
                {
                    q2.pb(in[ low ].a);
                    s = in[ low ].a;
                    mark[ s ] = true;
                }
            }
            }
    }
/*
7
0 2
1 3
2 4
3 5
4 6
5 7
6 0
*/
    reverse(q2.begin(), q2.end());
    int len = q1.size() + q2.size();
    int a = 0, b = 0; printf("%d", q2[ a++ ]);
    for(int i = 1; i < len; i++)
    {
        if(i & 1) printf(" %d", q1[ b++ ]);
        else printf(" %d", q2[ a++ ]);
    }
    puts("");
}
