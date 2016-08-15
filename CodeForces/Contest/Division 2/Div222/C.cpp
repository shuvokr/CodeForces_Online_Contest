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

template <class T> T sq(T x) {return x * x;}
template <class T> T gcd( T a, T b ) { while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <class T> T lcm ( T a, T b ) { return ( a / gcd ( a, b ) ) * b; }
template <class T> T power ( T a, T p ) { int res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}
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

void DFS(int i, int j);

char mazz[ 503 ][ 503 ];
int r, c, k, cou;
bool mark[ 503 ][ 503 ];

int main()
{
    //#ifdef localhost
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    CLR(mark, true);
    input();

    return 0;
}
void input()
{
    int emty = 0;
    scanf("%d %d %d", &r, &c, &k); getchar();
    for(int i = 0; i < r; i++)
    {
        gets(mazz[ i ]);
        for(int j = 0; j < c; j++) emty += mazz[ i ][ j ] == '.' ? 1 : 0;
    }
    if(k == 0)
    {
        for(int i = 0; i < r; i++) puts(mazz[ i ]);

    }
    else{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
        {
            if(mazz[ i ][ j ] == '.')
            {
                mazz[ i ][ j ] = 'X';
                printf("%d ", emty);
                if(emty - 1 == 0) {i = r, j = c; break;}
                for(int ii = i; ii < r; ii++)
                    for(int jj = j+1; jj < c; jj++)
                    {
                        if(mazz[ ii ][ jj ] == '.')
                        {
                            //puts("*********");
                            cou = 1; mark[ ii ][ jj ] = false;
                            printf("%d %d\n", ii, jj);
                            DFS(ii, jj);
                            //printf(" %d %d \n", emty-1, cou);
                            if(cou == emty - 1) k--, ii = r, jj = c, i = 0, j = 0;
                            if( !k ) ii = r, jj = c;
                            CLR(mark, true);
                        }
                    }
                if(cou != emty) mazz[ i ][ j ] = '.';
                else emty = emty - 1;
            }
            if( !k ) i = r, j = c;
        }
    for(int i = 0; i < r; i++) puts(mazz[ i ]);}
}
void DFS(int i, int j)
{
    for(int s = 0; s < 4; s++)
    {
        int x = i + diraction1[ s ];
        int y = j + diraction2[ s ];
        if(mazz[ x ][ y ] == '.' && mark[ x ][ y ])
        {
            mark[ x ][ y ] = false;
            cou++;
            DFS(x, y);
        }
    }
}

