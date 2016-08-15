#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define phl puts("ok")

void dp(int pos, int how);

struct data
{
    int val;
}in[ 5010 ];

int n;
bool mark;

int main()
{
    //freopen("input.txt", "r", stdin);
    int p, q, r, s, T, i;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        p = q = r = s = 0;

        for(i = 0; i < n; i++)
            scanf("%d", &in[ i ].val);

        mark = false;
        dp( 0, 0 );

    }
    return 0;
}
void dp(int pos, int how)
{
    int cou, p, x, y, q, r, s, poi, xx, yy, pp, qq, rr;
    for(int i = 0; i < n; i++)
    {
        p = in[i].val;
        pp = in[i].val;
        for(int j = i + 1; j < n; j++)
        {
            int val = in[j].val;
            int val2 = val;
            if(val > p)
            {
                q = val;
                for(int k = j + 1; k < n; k++)
                {
                    val = in[k].val;
                    val2 = val;
                    if(val < p)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            //printf("%d %d %d %d\n", p, q, r, in[l].val);
                            val = in[l].val;
                            if(val < q && val > p)
                            {
                                puts("YES");
                                mark = true;
                                i = j = k = l = n + 1;
                            }
                            else if(val > q && val < p)
                            {
                                puts("YES");
                                mark = true;
                                i = j = k = l = n + 1;
                            }
                        }
                    }
                    else if(val > p)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            //printf("%d %d %d %d\n", p, q, r, in[l].val);
                            val = in[l].val;
                            if(val > q && val < p)
                            {
                                puts("YES");
                                mark = true;
                                i = j = k = l = n + 1;
                            }
                        }
                    }
                }
            }
            else if(val < p)
            {
                q = val; cou++;
                y = j;
                for(int k = j + 1; k < n; k++)
                {
                    val = in[k].val;
                    r = val;
                    if(val > p)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            //printf("%d %d %d %d\n", p, q, r, in[l].val);
                            val = in[l].val;
                            if(val > q && val < p)
                            {
                                puts("YES");
                                mark = true;
                                i = j = k = l = n + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if(!mark)
    for(int i = 0; i < n; i++)
    {
        cou = 1;
        p = in[i].val; x = i;
        for(int j = i + 1; j < n; j++)
        {
            int val = in[j].val;
            if(val < p)
            {
                q = val; cou++;
                y = j;
                for(int k = j + 1; k < n; k++)
                {
                    val = in[k].val;
                    r = val;
                    if(val > p)
                    {
                        for(int l = k + 1; l < n; l++)
                        {
                            //printf("%d %d %d %d\n", p, q, r, in[l].val);
                            val = in[l].val;
                            if(val > q && val < p)
                            {
                                puts("YES");
                                mark = true;
                                i = j = k = l = n + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if(!mark) puts("NO");
}
/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

void dp(int pos);

int n;
bool mark, mamo[ 5010 ];
int in[ 5010 ];

int ar[ 0 ], ind;

int main()
{
    int T, i;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &in[ i ]);

        mark = false; ind = 0;
        memset(mamo, false, sizeof mamo);
        dp( 0 );

        puts(mark == true ? "YES" : "NO");
    }
    return 0;
}
void dp(int pos)
{
    if(pos >= n || mark) return ;
    if(ind == 4)
    {
        if(ar[2] < ar[0] && ar[0] < ar[3] && ar[3] < ar[1]) mark = true;
        if(ar[1] < ar[3] && ar[3] < ar[0] && ar[0] < ar[2]) mark = true;
        return;
    }

    //if(mamo[ pos ]) return;

    ar[ ind++ ] = in[ pos ];
    dp(pos + 1);
    ind--;

    dp(pos + 1);

    //mamo[ pos ] = true;
}

*/
