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
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200+2

#define white 0
#define black 1

typedef pair<int, int> pii;
typedef  vector<int> vi;
typedef vector<pii> vii;


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

/**************************Templet end*********************************/

bool mark[ 100005 ];
int res[ 100005 ] = { 0 }, n, m, in[ 100005 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tmp, cou = 1;
    scanf("%d %d", &n, &m);
    n++; m++;
    //for(int i = 1; i < 1000; i++) printf("%d ", res[ i ]);
    memset(mark, false, sizeof mark);
    for(int i = 1; i < n; i++) scanf("%d", &in[ i ]);
    for(int i = n - 1; i > 0; i--)
    {
        if( !mark[ in[ i ] ])
        {
            mark[ in[ i ] ] = true;
            res[ i ] = cou++;
        }
        else res[ i ] = res[i + 1];
    }
    for(int i = 1; i < m; i++) scanf("%d", &tmp), printf("%d\n", res[ tmp ]);
    return 0;
}

