#include <stdio.h>
using namespace std;
int add(int a, int b)
{
	int sum = a + b;
	return sum;
}

int mina()
{
	int x = add(2, 3);
	printf("%d\n", x);
	return 0;
}
