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
    int i, n, k, cou;
    scanf("%d %d", &n, &k);
    if(!k)
    {
        printf("%d", n);
        for(i = 1; i < n; i++) printf(" %d", i);
        puts(""); return 0;
    }
    if(k >= n) {puts("-1"); return 0;}
    if(k == n - 1)
    {
        printf("1");
        for(i = 2; i <= n; i++) printf(" %d", i);
        puts("");
        return 0;
    }
    if(n - k == 2)
    {
        printf("%d", n);
        for(i = 2; i < n; i++) printf(" %d", i);
        puts(" 1");
        return 0;
    }
    if((n - k) % 2 == 0) printf("%d", n);
    else printf("%d", n - 1);
    cou = 2;
    for(i = 1; i <= k; i++)
        printf(" %d", cou++);
    bool ultapalta = true;
    for(i = 2 + k; i < n; i++)
    {

        if(ultapalta)
        {
            printf(" %d", cou + 1);
            ultapalta = false;
        }
        else
        {
            printf(" %d", cou);
            cou += 2;
            ultapalta = true;
        }
    }
    puts(" 1");
    return 0;
}

