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
#define maxn 200+2
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


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/
bool retu(int d, int r);
char in[ 105 ][ 105 ];
int rc, val[] = {12, 6, 4, 3, 2, 1};
vector <int> res[ 110 ];

int main()
{
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    scanf("%d", &rc); getchar();
    for(int i = 0; i < rc; i++)
    {
        gets( in[ i ] );
        int pos = 0;
        res[ i ].clear();
        for(int k = 0; k < 6; k++)
            if(retu(val[ k ], i)) res[ i ].push_back( val[ k ] );
    }
    for(int i = 0; i < rc; i++)
    {
        if(!res[ i ].size()) puts("0");
        else
        {
            printf("%d", res[ i ].size());
            //printf("%dx%d", 12 / res[ i ][ 0 ], res[ i ][ 0 ]);
            for(int k = 0; k < res[ i ].size(); k++)
                printf(" %dx%d", 12 / res[ i ][ k ], res[ i ][ k ]);
            puts("");
        }
    }
}
bool retu(int d, int r)
{
    int i = 0;
    bool mr = false;
    while(in[ r ][ i ] != 'X') i++;
    for(int i = 0; i < 12; i++)
    {
        if(i >= d) return false;
        else
        {
            mr = true;
            for(int j = i; j < 12; j += d)
                if(in[ r ][ j ] != 'X') mr = false;
        }
        if( mr ) return true;
    }
    return false;
}
