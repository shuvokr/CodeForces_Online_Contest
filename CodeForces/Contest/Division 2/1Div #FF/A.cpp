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

#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

void input();

/**************************Templet end*********************************/

struct data
{
    int L, R;
}stor[ 100010 ];

int n, in[ 100010 ], ind;

int main()
{
    #ifdef monkey
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    input();

    return 0;
}
void input()
{
    //6 7 2 3 1 5 6
    sf("%d", &n); ind = 0;
    for(int i = 1; i <= n; i++) sf("%d", &in[ i ]);
    int flag = 0, last, rl, rr, len = 0;
    in[ 0 ] = -10; in[n + 1] = 1000000010;
    rl = rr = 1;
    int mark = 0;
    for(int i = 2; i <= n; i++)
    {
        if(in[ i ] > in[i - 1]) rr++, mark = 1;
        else
        {
            if(i == n) mark = 0;
            //pf("(%d %d %d %d)\n", in[ i ], in[i - 1], rl, rr);
            stor[ ind ].L = rl;
            stor[ ind ].R = rr;
            ind++; rr++; rl = rr;
        }
    }

    len = 1;
    stor[ ind ].L = rl;
    stor[ ind ].R = rr;
    ind++;

    for(int i = 0; i < ind; i++)
    {
        //pf("%d %d\n", stor[i].L, stor[i].R);
        int tmp = stor[ i ].R - stor[ i ].L + 1;
        if(stor[ i ].L != 1 || stor[ i ].R != n) tmp++;
        len = max(len, tmp);
    }

    for(int i = 1; i < ind; i++)
    {

        if(stor[ i ].R - stor[ i ].L == 0)
        {

            if(i != ind - 1)
            {
                int a = stor[i - 1].R, b = stor[ i ].L, c = stor[i + 1].L;
                if(in[ c ] - in[ a ] > 1)
                {
                    int tmp = stor[ i ].R - stor[ i ].L + 1 + stor[ i - 1 ].R - stor[ i - 1 ].L + 1 + stor[ i + 1 ].R - stor[ i + 1 ].L + 1;
                    len = max(len, tmp);
                }
            }

            int tmp = stor[ i ].R - stor[ i ].L + 1 + stor[ i - 1 ].R - stor[ i - 1 ].L + 1;
            len = max(len, tmp);
        }
        else if(stor[ i - 1 ].R - stor[ i - 1 ].L == 0)
        {
            int tmp = stor[ i ].R - stor[ i ].L + 1 + stor[ i - 1 ].R - stor[ i - 1 ].L + 1;
            len = max(len, tmp);
        }


        {
            int a = stor[i - 1].R - 1, b = stor[i - 1].R, c = stor[i].L, d = stor[ i ].L + 1;

            //pf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, in[ a ], in[ b ], in[ c ], in[ d ], in[d]-in[b],in[c]-in[a]);

            if(in[ d ] - in[ b ] > 1 || in[ c ] - in[ a ] > 1)
            {
                //pf("%d %d %d %d\n", stor[i - 1].L, stor[i - 1].R, stor[i].L, stor[i].R);
                int tmp = stor[ i ].R - stor[ i ].L + 1 + stor[ i - 1 ].R - stor[ i - 1 ].L + 1;
                len = max(len, tmp);
            }
        }
        len = max(len, stor[ i ].R - stor[ i ].L + 1);
    }

    pf("%d\n", len);
}


/*
50
804289384 846930887 681692778 714636916 957747794 424238336 719885387 649760493 596516650
189641422 25202363 350490028 783368691 102520060 44897764 967513927 365180541 540383427 304089173
303455737 35005212 521595369 294702568 726956430 336465783 861021531 59961394 89018457 101513930
125898168 131176230 145174068 233665124 278722863 315634023 369133070 468703136 628175012
635723059 653377374 656478043 801979803 859484422 914544920 608413785 756898538 734575199 973594325 149798316 38664371

*/

