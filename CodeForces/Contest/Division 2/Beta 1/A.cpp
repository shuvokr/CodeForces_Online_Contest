#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    long long n, m, a, res, tmp;
    scanf("%I64d %I64d %I64d", &n, &m, &a);
    long long x = ceil(double(m)/double(a));
    long long y = ceil(double(n)/double(a));
    printf("%I64d\n", x*y);
    return 0;
}
