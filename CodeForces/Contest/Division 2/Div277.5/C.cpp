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

int DP(int pos, int tot);

int mamo[ 110 ][ 910 ];
int len, sum, all = 0;
char v[ 110 ], a[ 110 ], b[ 110 ];
bool marka, markb;

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
    sf("%d %d", &len, &sum);
    if(sum == 0)
    {
        if(len > 1)
        {
            puts("-1 -1");
            return;
        }
    }

    int xx = log10(sum) + 1;
    if(xx > len)
    {
        puts("-1 -1");
        return;
    }

    if(len == 1 && sum == 0)
    {
        puts("0 0");
        return;
    }

    marka = markb = false;
    for(int i = 0; i < len; i++) a[ i ] = '9', b[ i ] = '0';
    a[ len ] = b[ len ] = v[ len ] = NULL;
    //cout << a << " " << b << " " << v << endl;
    CLR(mamo, -1);
    int res = DP(0, 0);
    int xxx = 0, yyy = 0;
    for(int i = 0; i < len; i++) xxx += a[ i ] - 48;
    for(int i = 0; i < len; i++) yyy += b[ i ] - 48;
    if(xxx != sum || yyy != sum)
    {
        puts("-1 -1");
        return;
    }
    cout << a << " " << b << endl;
    //cout << all << endl;
}
int DP(int pos, int tot)
{
    if(pos == len)
    {
        if(tot == sum)
        {
            string sk = toString( v );
            //cout << v << endl;
            sort(v, v + pos);

            int ii = 0;
            while(v[ ii ] == '0' && ii < pos)
            {
                ii++;
            }

            if(ii != pos)
            {
                swap(v[ ii ], v[ 0 ]);
            }

            string x = toString( v ), y = toString( a );
            if(y > x && v[ 0 ] != '0')
            {
                marka = true;
                for(int i = 0; i < pos; i++) a[ i ] = v[ i ];
            }

            if(ii != pos) swap(v[ ii ], v[ 0 ]);

            reverse(v, v + pos);
            if(v[ 0 ] != '0')
            {
                x = toString( v ), y = toString( b );
                if(y < x)
                {
                    markb = true;
                    for(int i = 0; i < pos; i++) b[ i ] = v[ i ];
                }
            }
            for(int i = 0; i < pos; i++) v[ i ] = sk[ i ];
        }
        return 0;
    }
    int &ret = mamo[ pos ][ tot ];
    if(ret != -1)
    {
        //all++;
        return ret;
    }
    int i;

    for(int i = 0; i < 10; i++)
    {
        if(tot + i <= sum)
        {
            string cv = toString(i);
            v[ pos ] = cv[ 0 ];
            ret = DP(pos + 1, i + tot);
        }
    }
    return ret;
}
