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
#define si1(a) scanf("%d", &a)
#define pi1(a) printf("%d\n", a)
#define si2(a, b) scanf("%d %d", &a, &b)
#define pi2(a, b) printf("%d %d\n", a, b)
#define si3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pi3(a, b, c) printf("%d %d %d\n", a, b, c)

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

void Input();
const int INF = 2147483647;
const long long LINF = 9223372036854775807ll;
/**************************Templet end*********************************/

void BFSb(int s);
void BFSt(int s);

struct cost
{
	int fst, snd;
}tcost[ 410 ],bcost[ 410 ];

vector <vi> bus, train;
int n, m;
bool mark[ 410 ][ 410 ];

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    Input();

    return 0;
    /// Not use cin/cout without necessity. This a causes of TLE :p
}
void Input()
{
	cin >> n >> m; CLR(mark, true);
	bus.assign(n + 5, vi());
	train.assign(n + 5, vi());
	for(int i = 0, u, v; i < m; i++) 
	{
		si2(u, v);
		mark[ u ][ v ] = mark[ v ][ u ] = false;
		train[ u ].push_back( v );
		train[ v ].push_back( u );
	}
	for(int u = 1; u <= n; u++)
		for(int v = u + 1; v <= n; v++)
		{
			if(mark[ u ][ v ])
			{
				bus[ u ].push_back( v );
				bus[ v ].push_back( u );
			}
		}
		
	for(int i = 1; i <= n; i++) bcost[i].fst = bcost[i].snd = tcost[ i ].fst = tcost[i].snd = INF;
	BFSb( 1 ); BFSt( 1 );
	bool ck = false;
	for(int i = 1; i < n; i++)
		if(tcost[i].snd == INF && tcost[i].fst == bcost[ i ].fst && bcost[ i ].snd == INF) ck = true, i = n;
	
	if(bcost[n].fst == INF || tcost[n].fst == INF) ck = true;
	
	if( ck ) puts("-1");
	else pi1(max(bcost[ n ].fst, tcost[ n ].fst));
}
void BFSb(int s)
{
	queue <int> q;
	q.push( s );
	bcost[s].fst = bcost[s].snd = 0;
	while( !q.empty() )
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < bus[ u ].size(); i++)
		{
			int v = bus[ u ][ i ];
			if(bcost[ v ].fst > bcost[ u ].fst + 1)
			{
				bcost[ v ].snd = min(bcost[ v ].snd, bcost[ v ].fst);
				bcost[ v ].fst = bcost[ u ].fst + 1;
				q.push( v );
			}
		}
	}
}
void BFSt(int s)
{
	queue <int> q;
	q.push( s );
	tcost[s].fst = tcost[s].snd = 0;
	while( !q.empty() )
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < train[ u ].size(); i++)
		{
			int v = train[ u ][ i ];
			if(tcost[ v ].fst > tcost[ u ].fst + 1)
			{
				tcost[ v ].snd = min(tcost[ v ].snd, tcost[ v ].fst);
				tcost[ v ].fst = tcost[ u ].fst + 1;
				q.push( v );
			}
		}
	}
}
