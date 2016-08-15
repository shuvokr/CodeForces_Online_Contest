#include <cstdio>
#include <cstring>

int main()
{
    int len1, len2, len3, len4;
    char in[ 110 ], res;
    gets( in ); len1 = strlen( in ) - 2;
    gets( in ); len2 = strlen( in ) - 2;
    gets( in ); len3 = strlen( in ) - 2;
    gets( in ); len4 = strlen( in ) - 2;

    int mark = 0;
    //printf("%d %d %d %d\n", len1, len2, len3, len4);

    if(len1 >= len2 << 1 && len1 >= len3 << 1 && len1 >= len4 << 1)
    {
        mark++; res = 'A';
    }
    if(len2 >= len1 << 1 && len2 >= len3 << 1 && len2 >= len4 << 1)
    {
        mark++; res = 'B';
    }
    if(len4 >= len1 << 1 && len4 >= len2 << 1 && len4 >= len3 << 1)
    {
        mark++; res = 'D';
    }
    if(len3 >= len1 << 1 && len3 >= len2 << 1 && len3 >= len4 << 1)
    {
        mark++; res = 'C';
    }

    if(len1 << 1 <= len2 && len1 << 1 <= len3 && len1 << 1 <= len4)
    {
        mark++; res = 'A';
    }
    if(len2 << 1 <= len1 && len2 << 1 <= len3 && len2 << 1 <= len4)
    {
        mark++; res = 'B';
    }
    if(len4 << 1 <= len1 && len4 << 1 <= len2 && len4 << 1 <= len3)
    {
        mark++; res = 'D';
    }
    if(len3 << 1 <= len1 && len3 << 1 <= len2 && len3 << 1 <= len4)
    {
        mark++; res = 'C';
    }
    if(mark == 1) printf("%c\n", res);
    else puts("C");

    return 0;
}
