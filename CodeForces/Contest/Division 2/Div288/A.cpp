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
template <class T> T power ( T a, T p ) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
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

bool f(int x, int y);
bool isok(int x1, int y1, int x2, int y2, int x3, int y3);

bool mark[ 1010 ][ 1010 ];
int r, c, k, a1, b1, a2, b2, a3, b3;

int main()
{
    #ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    input();

    return 0;
}
void input()
{
    cin >> r >> c >> k;
    CLR(mark, true);
    int res = 0;
    for(int i = 0, a, b; i < k; i++)
    {
        cin >> a >> b;
        mark[ a ][ b ] = false;

        a1 = a, b1 = b + 1, a2 = a + 1, b2 = b, a3 = a + 1, b3 = b + 1;
        if(f(a1, b1) && f(a2, b2) && f(a3, b3))
        {
            if(isok(a1, b1, a2, b2, a3, b3) && !res) res = i + 1;
        }

        a1 = a, b1 = b + 1, a2 = a - 1, b2 = b, a3 = a - 1, b3 = b + 1;
        if(f(a1, b1) && f(a2, b2) && f(a3, b3))
        {
            if(isok(a1, b1, a2, b2, a3, b3) && !res) res = i + 1;
        }

        a1 = a, b1 = b - 1, a2 = a - 1, b2 = b, a3 = a - 1, b3 = b - 1;
        if(f(a1, b1) && f(a2, b2) && f(a3, b3))
        {
            if(isok(a1, b1, a2, b2, a3, b3) && !res) res = i + 1;
        }

        a1 = a, b1 = b - 1, a2 = a + 1, b2 = b, a3 = a + 1, b3 = b - 1;
        if(f(a1, b1) && f(a2, b2) && f(a3, b3))
        {
            if(isok(a1, b1, a2, b2, a3, b3) && !res) res = i + 1;
        }
    }
    cout << res << endl;
}
bool f(int x, int y)
{
    if(x >= 1 && x <= r && y >= 1 && y <= c) return true;
    return false;
}
bool isok(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(mark[x1][y1] == false && mark[x2][y2] == false && mark[x3][y3] == false) return true;
    return false;
}
