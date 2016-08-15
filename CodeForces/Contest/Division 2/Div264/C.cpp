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

int N, board[ 2010 ][ 2010 ];
long long col[ 2010 ], row[ 2010 ], mamo[ 2010 ][ 2010 ];

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
    memset(mamo, 0, sizeof mamo);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++) scanf("%d", &board[ i ][ j ]);
    /****************************/
    for(int i = 1; i <= N; i++)
    {
        long long sum = 0ll;
        int x = i, y = 1;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            sum += board[ x ][ y ];
            x--; y++;
        }
        x = i, y = 1;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            mamo[ x ][ y ] = sum;
            x--; y++;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        long long sum = 0ll;
        int x = N, y = i;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            sum += board[ x ][ y ];
            x--; y++;
        }

        x = N, y = i;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            mamo[ x ][ y ] = sum;
            x--; y++;
        }
    }
    /**********************************/
    /**********************************/
    for(int i = N; i > 0; i--)
    {
        long long sum = 0ll;
        int x = i, y = 1;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            sum += board[ x ][ y ];
            x++; y++;
        }

        x = i, y = 1;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            mamo[ x ][ y ] += sum - board[ x ][ y ];
            x++; y++;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        long long sum = 0ll;
        int x = 1, y = i;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            sum += board[ x ][ y ];
            x++; y++;
        }

        x = 1, y = i;
        while(x > 0 && x <= N && y > 0 && y <= N)
        {
            mamo[ x ][ y ] += sum - board[ x ][ y ];
            x++; y++;
        }
    }

    long long S = -1, L = -1;
    int x1, y1, x2, y2;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if((i + j) % 2)
            {
                if(S < mamo[ i ][ j ])
                {
                    S = mamo[ i ][ j ];
                    x1 = i; y1 = j;
                }
            }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(!((i + j) % 2))
            {
                if(L < mamo[ i ][ j ])
                {
                    L = mamo[ i ][ j ];
                    x2 = i; y2 = j;
                }
            }

    cout << S + L << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
