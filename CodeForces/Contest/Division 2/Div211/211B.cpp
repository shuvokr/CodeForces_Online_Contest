#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
int ar[ 200000 ];
int main()
{
    int i, n, k, res, po;
    scanf("%d %d", &n, &k);
        res = 1000000000; ar[ 0 ] = 0;

        for(i = 1; i <= n; i++)
        {
            scanf("%d", &ar[ i ]);
            ar[ i ] += ar[i - 1];
        }

        for(int i = k; i <= n; i++)
        {
            int tot = ar[ i ] - ar[i - k];
            if(res > tot)
            {
                res = tot;
                po = i - k + 1;
            }
        }

        printf("%d\n", po);
    return 0;
}
