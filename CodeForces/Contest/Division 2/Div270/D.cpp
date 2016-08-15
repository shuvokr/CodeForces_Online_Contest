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
#define INF 100000000000000
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
typedef pair<lld, lld> pi;
typedef  vector<lld> vi;
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

struct data
{
    int nod, time;
    data() {}
    data(int a, int b):nod(a), time(b) {}
    bool operator<(const data &x) const
    {
        return time < x.time;
    }
};

void Dijkstra(lld s);

long long adjm[ 2010 ][ 2010 ], n, cost[ 2010 ];
vector <vpi> graph;

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
    while(cin >> n)
    {
        bool ck = false;
        for(lld i = 1; i <= n; i++)
            for(lld j = 1; j <= n; j++)
            {
                cin >> adjm[ i ][ j ];
                if(i == j && adjm[ i ][ j ]) ck = true;
            }

        if( ck )
        {
            puts("NO");
            return;
        }

        lld start;
        graph.assign(n + 2, vpi());
        for(lld i = 1; i <= n; i++)
            for(lld j = 1; j <= n; j++)
            {
                if(adjm[ i ][ j ])
                {
                    start = i;
                    graph[ i ].pb(pi(j, adjm[ i ][ j ]));
                    graph[ j ].pb(pi(i, adjm[ i ][ j ]));
                }
                if(adjm[ i ][ j ] != adjm[ j ][ i ]) ck = true, i = j = n + 1;
            }

        if( ck )
        {
            puts("NO");
            return;
        }

        for(lld k = 1; k <= n; k++)
        {
            for(lld i = 1; i <= n; i++) cost[ i ] = INF;
            cost[ k ] = 0ll; Dijkstra( k );
            for(lld i = 1; i <= n; i++)
            {
                if(cost[ i ] != adjm[ k ][ i ])
                {
                    ck = true;
                    i = k = n + 1;
                }
            }
        }
        puts(ck ? "NO" : "YES");
        return;
    }
}
void Dijkstra(lld u)
{
    priority_queue <data> pq;
    pq.push(data(u, 0));
    data tmp;
    while(!pq.empty())
    {
        tmp = pq.top(); pq.pop();
        lld nd = tmp.nod, tm = tmp.time;
        if(cost[ nd ] == tm)
        {
            for(lld i = 0; i < graph[ nd ].size(); i++)
            {
                pi pr = graph[ nd ][ i ];
                if(cost[ nd ] + pr.second < cost[ pr.first ])
                {
                    cost[ pr.first ] = cost[ nd ] + pr.second;
                    pq.push(data(pr.first, cost[ pr.first ]));
                }
            }
        }
    }
}