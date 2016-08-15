/************************************

    Shuvo
    Problem name :
    Problem ID   :
    Problem algo :
    Note         :

*************************************/

/**********************************Templet start***********************************/
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
//const int pr = 500001;
//int prime[ 41539 ], ind;
//bool mark[ pr ];
//void primelist()
//{
//    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
//    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
//    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
//        if(mark[ i ])
//            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
//    prime[ 0 ] = 2; ind = 1;
//    for(int i = 3; i < pr; i += 2)
//        if(mark[ i ]) ind++; printf("%d\n", ind);
//}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

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
    double x1[ 5 ], y1[ 5 ], x2[ 5 ], y2[ 5 ], len[ 5 ];
    bool mark = false;
    for(int i = 1; i < 5; i++)
    {
        sf("%lf %lf %lf %lf", &x1[ i ], &y1[ i ], &x2[ i ], &y2[ i ]);
        if(x1[ i ] < 0 || y1[ i ] < 0 || x2[ i ] < 0 || y2[ i ] < 0) mark = true;
        len[ i ] = cordinatlenth(x1[ i ], y1[ i ], x2[ i ], y2[ i ]);
    }
    if(mark){ puts("NO"); return; }
    pf("%.3lf %.3lf %.3lf %.3lf\n", len[ 1 ], len[ 2 ], len[ 3 ], len[ 4 ]);
    if(len[ 1 ] == len[ 2 ] && len[ 3 ] == len[ 4 ])
    {
        //phl;
        if((x1[ 1 ] == x1[ 3 ] && y1[ 1 ] == y1[ 3 ] && x2[ 2 ] == x2[ 4 ] && y2[ 2 ] == y2[ 4 ]) ||
           (x1[ 1 ] == x1[ 4 ] && y1[ 1 ] == y1[ 4 ] && x2[ 2 ] == x2[ 3 ] && y2[ 2 ] == y2[ 3 ])) puts("YES");
        else puts("NO");
    }
    else if(len[ 1 ] == len[ 3 ] && len[ 2 ] == len[ 4 ])
    {
        if((x1[ 1 ] == x1[ 2 ] && y1[ 1 ] == y1[ 2 ] && x2[ 3 ] == x2[ 4 ] && y2[ 3 ] == y2[ 4 ]) ||
           (x1[ 1 ] == x1[ 4 ] && y1[ 1 ] == y1[ 4 ] && x2[ 3 ] == x2[ 2 ] && y2[ 3 ] == y2[ 2 ])) puts("YES");
        else puts("NO");
    }
    else if(len[ 1 ] == len[ 4 ] && len[ 2 ] == len[ 3 ])
    {
        if((x1[ 1 ] == x1[ 2 ] && y1[ 1 ] == y1[ 2 ] && x2[ 4 ] == x2[ 3 ] && y2[ 4 ] == y2[ 3 ]) ||
           (x1[ 1 ] == x1[ 3 ] && y1[ 1 ] == y1[ 3 ] && x2[ 4 ] == x2[ 2 ] && y2[ 4 ] == y2[ 2 ])) puts("YES");
        else puts("NO");
    }
    else puts("NO");
}
