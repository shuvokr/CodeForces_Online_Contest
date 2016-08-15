#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    char a[ 100 ], b[ 100 ], c[ 100 ];
    while(~scanf("%s %s", a, b))
    {
        int k = 0;
        int lena = strlen( a ) - 1;
        int lenb = strlen( b ) - 1;
        int len = lena > lenb ? lena : lenb;
        int cr = 0;
        while(lena >= 0 || lenb >= 0)
        {
            int x = 0, y = 0;
            if(lena >= 0) x = a[ lena ] - 48;
            if(lenb >= 0) y = b[ lenb ] - 48;
            x = x + y + cr;
            y = x % 10;
            cr = x / 10;
            c[ k++ ] = y + 48;
            lena--; lenb--;
        }
        reverse(c, c + k);
        c[ k ] = NULL;
        if( cr ) printf("%d", cr);
        puts( c );
        memset(a, 0, 100);
        memset(b, 0, 100);
        memset(c, 0, 100);
    }
    return 0;
}
