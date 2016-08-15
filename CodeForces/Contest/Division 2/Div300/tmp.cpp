/***************** Shuvo *****************/
/****************** DIU *****************/

#pragma comment(linker, "/stack:64000000")

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
const int INF = 1 << 30;
/**************************Templet end*********************************/

lld R, N;
char p1[ 3000 ], p2[ 3000 ], in[ 3000 ];

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
    int kag = 0;
    while(sf("%lld", &R) && R)
    {
        sf("%lld", &N);

        CLR(in, 0);
        CLR(p1, 0);
        CLR(p2, 0);

        while(gets( in ))
        {
            if(in[ 0 ] != NULL) break;
        }
        //puts( in );

        int len = strlen( in );
        int cou = 0;


        for(int i = 0; i < len; i++) if(in[ i ] == '"') cou++;

        if(cou == 0)
        {
            char *tok;
            tok = strtok(in, " ");
            while( tok != NULL )
            {
                strcpy(p1, tok);
                tok = strtok(NULL, " ");
                strcpy(p2, tok);
                break;
            }
            //phl;
        }
        /*****************************************************/
        else if(cou == 2)
        {
            int x = -1, y = -1, flag;
            for(int i = 0; i < len; i++)
            {
                if(in[ i ] == '"')
                {
                    flag = 0;
                    x = i;
                    i++;
                    while(in[ i ] != '"')
                    {
                        if(in[ i ] != 32) flag = 1;
                        i++;
                    }
                    y = i;
                    i++;
                    break;
                }
            }

                if(flag == 0)
                {
                    int tt = 0;
                    for(int ii = 0; ii < x; ii++) if(in[ ii ] != 32) tt = 1, ii = x;

                    if(tt == 1)
                    {
                        int ii = 0;
                        while(in[ ii ] == 32) ii++;
                        int jj = x - 1;
                        while(in[ jj ] == 32) jj--;

                        int pp = 0;
                        for(int kk = ii; kk <= jj; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL; pp = 0;
                        x++; y--;

                        while(in[ x ] == 32) x++;
                        while(in[ y ] == 32) y--;
                        for(int kk = x; kk <= y; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL;
                    }
                    else
                    {
                        int ii = y + 1;
                        while(in[ ii ] == 32) ii++;
                        int jj = strlen( in ) - 1;
                        while(in[ jj ] == 32) jj--;

                        int pp = 0;
                        for(int kk = ii; kk <= jj; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL; pp = 0;
                        x++; y--;

                        while(in[ x ] == 32) x++;
                        while(in[ y ] == 32) y--;
                        for(int kk = x; kk <= y; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL;
                    }
                }
                else
                {
                    int tt = 0;
                    for(int ii = 0; ii < x; ii++) if(in[ ii ] != 32) tt = 1, ii = x;

                    if(tt == 1)
                    {

                        int ii = 0;
                        while(in[ ii ] == 32) ii++;
                        int jj = x - 1;
                        while(in[ jj ] == 32) jj--;

                        int pp = 0;
                        for(int kk = ii; kk <= jj; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL; pp = 0;

                        x++; y--;

                        while(in[ x ] == 32) x++;
                        while(in[ y ] == 32) y--;

                        for(int kk = x; kk <= y; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL;
                    }
                    else
                    {

                        int ii = y + 1;
                        while(in[ ii ] == 32) ii++;
                        int jj = strlen( in ) - 1;
                        while(in[ jj ] == 32) jj--;

                        int pp = 0;
                        for(int kk = ii; kk <= jj; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL; pp = 0;
                        x++; y--;

                        while(in[ x ] == 32) x++;
                        while(in[ y ] == 32) y--;

                        for(int kk = x; kk <= y; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL;
                    }
                }

        }
        /**********************************************************************/
            else
            {
                int s = 0;
                for(int i = 0; i < len; i++)
                {
                    if(in[ i ] == '"')
                    {
                        int x = i, fl = 0, y = i + 1;
                        while(in[ y ] != '"')
                        {
                            y++;
                            if(in[ y ] != 32) fl = 1;
                        }
                        i = y + 1;

                        if(fl == 0)
                        {
                            int pp = 0;
                            if(s == 0)
                            {
                                x++; y--;

                                while(in[ x ] == 32) x++;
                                while(in[ y ] == 32) y--;
                                for(int kk = x; kk <= y; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL;
                                s++;
                            }
                            else
                            {
                                x++; y--;

                                while(in[ x ] == 32) x++;
                                while(in[ y ] == 32) y--;
                                for(int kk = x; kk <= y; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL;
                            }
                        }
                        else
                        {
                            x++; y--;
                            while(in[ x ] == 32) x++;
                            while(in[ y ] == 32) y--;
                            int pp = 0;
                            if(s == 0)
                            {
                                for(int kk = x; kk <= y; kk++) p1[ pp++ ] = in[ kk ]; p1[ pp ] = NULL;
                                s++;
                            }
                            else
                            {
                                for(int kk = x; kk <= y; kk++) p2[ pp++ ] = in[ kk ]; p2[ pp ] = NULL;
                            }
                        }
                    }
                }
            }

        lld tmp = R / N;
        if(R % N) tmp++;
        pf("%d. ", ++kag);
        if(tmp % 2) cout << p1 << endl;
        else cout << p2 << endl;
    }
}
