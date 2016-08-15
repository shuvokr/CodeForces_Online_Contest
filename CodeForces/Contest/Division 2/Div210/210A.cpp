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

int main()
{
    int i, j, n, k;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            j == i ? printf("%d", k) : printf("0");
            if(j != n - 1) printf(" ");
        }
        puts("");
    }
    return 0;
}
