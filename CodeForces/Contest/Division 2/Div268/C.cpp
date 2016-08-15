#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n < 4) puts("NO");
    else if(n == 4) puts("YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24");
    else if(n == 5) puts("YES\n4 * 5 = 20\n3 - 1 = 2\n2 + 2 = 4\n20 + 4 = 24");
    else
    {
        puts("YES\n6 * 4 = 24\n5 - 3 = 2\n2 - 2 = 0\n1 * 0 = 0");
        for(int i = 7; i <= n; i++) printf("%d * 0 = 0\n", i);
        puts("24 + 0 = 24");
    }
    return 0;
}
