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

void print(int num);

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
    int in;
    cin >> in;
    if(in < 21)
    {
        print( in );
        return;
    }
    else
    {
        if(in < 30)
        {
            print(20);
            //pf("-");
            if(in - 20) pf("-"),print(in - 20);
            return;
        }
        if(in < 40)
        {
            print(30);
            //pf("-");
            if(in - 30)pf("-"),print(in - 30);
            return;
        }
        if(in < 50)
        {
            print(40);
            //pf("-");
            if(in - 40)pf("-"),print(in - 40);
            return;
        }
        if(in < 60)
        {
            print(50);
            //pf("-");
            if(in - 50)pf("-"),print(in - 50);
            return;
        }
        if(in < 70)
        {
            print(60);
            //pf("-");
            if(in - 60)pf("-"),print(in - 60);
            return;
        }
        if(in < 80)
        {
            print(70);
            //pf("-");
            if(in - 70)pf("-"),print(in - 70);
            return;
        }
        if(in < 90)
        {
            print(80);
            //pf("-");
            if(in - 80)pf("-"),print(in - 80);
            return;
        }
        if(in < 100)
        {
            print(90);
            if(in - 90)pf("-"),print(in - 90);
            return;
        }
    }
}
void print(int num)
{
    if(num == 1) pf("one");
    if(num == 2) pf("two");
    if(num == 3) pf("three");
    if(num == 4) pf("four");
    if(num == 5) pf("five");
    if(num == 6) pf("six");
    if(num == 7) pf("seven");
    if(num == 8) pf("eight");
    if(num == 9) pf("nine");
    if(num == 0) pf("zero");
    if(num == 10) pf("ten");
    if(num == 11) pf("eleven");
    if(num == 12) pf("twelve");
    if(num == 13) pf("thirteen");
    if(num == 14) pf("fourteen");
    if(num == 15) pf("fifteen");
    if(num == 16) pf("sixteen");
    if(num == 17) pf("seventeen");
    if(num == 18) pf("eighteen");
    if(num == 19) pf("nineteen");
    if(num == 20) pf("twenty");
    if(num == 30) pf("thirty");
    if(num == 40) pf("forty");
    if(num == 50) pf("fifty");
    if(num == 60) pf("sixty");
    if(num == 70) pf("seventy");
    if(num == 80) pf("eighty");
    if(num == 90) pf("ninety");
}
