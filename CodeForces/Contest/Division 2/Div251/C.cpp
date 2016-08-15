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
    int n ,k, p, in[ 100010 ], odd = 0, even = 0;
    vector <int> ev;
    vector <int> od;
    sf("%d %d %d", &n, &k, &p);
    for(int i = 0; i < n; i++)
    {
        sf("%d", &in[ i ]);
        if(in[ i ] % 2)
        {
            od.pb( in[ i ] );
            odd++;
        }
        else
        {
            ev.pb( in[ i ] );
            even++;
        }
    }
    int oddlen = od.size(), evenlen = ev.size();
    int q = k - p;
    int b = oddlen - q;
    if(oddlen < q || b % 2)
    {
        puts("NO");
        return;
    }

    if(evenlen + (b / 2) < p)
    {
        puts("NO");
        return;
    }
    puts("YES");

    if(q)
    {
    for(int i = 0; i < q - 1 && i < oddlen; i++)
    {
        printf("1 %d\n", od[ i ]);
    }

    if( p ) printf("1 %d\n", od[ q - 1 ]);
    else
    {
        printf("%d %d", evenlen + 1 + oddlen - q, od[ q - 1 ]);
        for(int j = q; j < oddlen; j++) pf(" %d", od[ j ]);
        for(int j = 0; j < evenlen; j++) pf(" %d", ev[ j ]);
        puts(""); return ;
    }
    }
    int cou = 0, tt = 0;
    for(int i = 0; i < evenlen; i++)
    {
        if(cou + 1 == p)
        {
            //puts("*");
            pf("%d", evenlen - i + b);
            for(int j = i; j < evenlen; j++) printf(" %d", ev[ j ]);
            for(int j = q; j < oddlen; j++) printf(" %d", od[ j ]);
            puts(""); return;
        }
        cou++;
        if(i == evenlen - 1 && cou == p){tt = 1; break;}
        printf("1 %d\n", ev[ i ]);
    }

    if(cou + 1 == p)
        {
            //puts("*");
            if(tt == 1) printf("%d %d", oddlen - q + 1, ev[ evenlen - 1 ]);
            else pf("%d", oddlen - q);
            //for(int j = i; j < evenlen; j++) printf(" %d", ev[ j ]);
            for(int j = q; j < oddlen; j++) printf(" %d", od[ j ]);
            puts(""); return;
        }

    if(cou + 1 != p)
    {
        for(int i = q; i < oddlen; i += 2)
        {
            if(cou + 1 == p)
            {
                //puts("***");
                pf("%d", oddlen - i);
                for(int j = i; j < oddlen; j++) printf(" %d", od[ j ]);
                puts(""); return;
            }
            cou++;
            printf("2 %d %d\n", od[ i ], od[i + 1]);
        }
    }
}
