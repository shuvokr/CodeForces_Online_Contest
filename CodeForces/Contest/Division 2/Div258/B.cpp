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
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) ind++; printf("%d\n", ind);
}

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

void input();

/**************************Templet end*********************************/

int in[ 100010 ];

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
    int n, s1, s2, s11, s22;
    while(~sf("%d", &n))
    {
        for(int i = 0; i < n; i++) sf("%d", &in[ i ]);
        if(n == 1) printf("yes\n1 1\n");
        else if(n == 2)
        {
            if(in[ 0 ] > in[ 1 ]) printf("yes\n1 2\n");
            else printf("yes\n1 1\n");
        }
        else
        {
            int i = 0;
            while(i + 1 < n && in[ i ] < in[i + 1]) i++;
            if(i == n - 1) printf("yes\n1 1\n");
            else
            {
                int k = i;
                while(k + 1 < n && in[ k ] > in[k + 1]) k++;
                if(k == n - 1)
                {
                    //printf("   %d %d\n", i, k);
                    bool mark = true;
                    int a = min(in[ i ], in[ k ]);
                    int b = max(in[ i ], in[ k ]);
                    //printf("%d %d**%d %d", a, in[i - 1], b, in[k - 1]);
                    if(i - 1 > -1 && a < in[i - 1]) mark = false;
                    if(k + 1 < n && b > in[k + 1]) mark = false;
                    if( mark ) printf("yes\n%d %d\n", i + 1, k + 1);
                    else puts("no");
                }
                else
                {
                    bool mark = true;
                    int x = k + 1;
                    //printf(" %d\n", x);
                    while(x + 1 < n)
                    {
                        if(in[ x ] > in[x + 1]) {mark = false; break;}
                        else x++;
                    }
                    int a = min(in[ i ], in[ k ]);
                    int b = max(in[ i ], in[ k ]);
                    //printf("%d %d**%d %d", a, in[i - 1], b, in[k - 1]);
                    if(i - 1 > -1 && a < in[i - 1]) mark = false;
                    if(k + 1 < n && b > in[k + 1]) mark = false;
                    if( mark ) printf("yes\n%d %d\n", i + 1, k + 1);
                    else puts("no");
                }
            }

        }
    }
}

