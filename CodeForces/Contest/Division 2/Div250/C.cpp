#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

long long DP(int pos);
bool isok();

vector <vi> graph;

bool mark[ 1010 ], tmp[ 1010 ];
long long cost[ 1010 ], mres, mamo[ 1010 ], res, enrgy[ 1010 ];
int node, edge;


int main()
{
    scanf("%d %d", &node, &edge);
    for(int i = 1; i <= node; i++) scanf("%I64d", &enrgy[ i ]);
    res = 0;
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        res += min(enrgy[ u ], enrgy[ v ]);
    }
    printf("%I64d\n",res);

    return 0;
}
long long DP(int pos)
{

}
bool isok()
{
    for(int i = 1; i <= node; i++) if(mark[ i ]) return false;
    return true;
}
