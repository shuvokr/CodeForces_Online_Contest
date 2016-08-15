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

struct data
{
    int val, ind;
}tmp[ 10010 ];

bool cmp(const data &x, const data &y)
{
    return (x.val < y.val);
}

bool cmp1(const data &x, const data &y)
{
    return (x.ind < y.ind);
}

int n, k, ans, cou[ 10 ];
char in[ 10010 ];
vector <int> v;

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
    cin >> n >> k >> in; CLR(cou, 0);
    for(int i = 0; i < n; i++) cou[ in[i] - '0' ]++;

    ans = 1000000000; int tag, sum = 0;
    int couu[ 12 ]; CLR(couu, 0);
    vector <int> xx; xx.clear();

    for(int i = 0; i < 10; i++)
    {
        v.clear();
        for(int j = 0; j < n; j++) v.pb( abs((in[j] - '0') - i) );
        sort(v.begin(), v.end());
        int ln = k - cou[ i ];
        if(ln < 1)
        {
            puts("0");
            puts( in );
            return;
        }
        sum = 0;
        for(int j = 0;; j++)
        {
            if(ln == 0) break;
            if(v[j] == 0) continue;
            ln--;
            sum += v[ j ];
        }
        //pf("%d %d %d\n", i, sum, k - cou[i]);
        if(ans > sum && ln == 0)
        {
            //pf("%d %d %d\n", sum, i, ln);
            ans = sum;
            tag = i;
            xx.clear();
            xx.pb( i );
        }
        else if(ans == sum && ln == 0) xx.pb( i );
    }
    //pf("%d\n", xx[1]);
    string str, st = in;
    for(int i = 0; i < n; i++) str += '9';

    for(int s = 0; s < xx.size(); s++)
    {
        tag = xx[ s ]; //pf("*%d ", tag);


        v.clear();
        for(int j = 0; j < n; j++) v.pb( abs((in[j] - '0') - tag) );
        sort(v.begin(), v.end());

        CLR(couu, 0); int ln = k - cou[ tag ];
        for(int j = 0;; j++)
        {
            if(ln == 0) break;
            if(v[j] == 0) continue;
            ln--; couu[ v[j] ]++;
        }

        ln = k - cou[ tag ];

        for(int j = 0; ln && j < n; j++)
        {
            int num = in[ j ] - 48, t = abs(num - tag);
            if(couu[t] > 0 && in[j] - 48 > tag) { couu[t]--; in[j] = tag + 48; ln--; }
        }

        for(int j = n - 1; ln && j >= 0; j--)
        {
            int num = in[ j ] - 48, t = abs(num - tag);
            if(couu[t] > 0 && in[ j ] - 48 < tag) { couu[t]--; in[j] = tag + 48; ln--; }
        }
        //puts( in );
        if(str > in) str = in; //puts( in );
        for(int ii = 0; ii < n; ii++) in[ii] = st[ii];
    }
    pf("%d\n", ans);
    cout << str << endl;
    //puts("393333393333883383337333333933778733383333373");
}
/*
45 32
293440596342887581257444442930778730382520372
10 6
0001112223
*/
