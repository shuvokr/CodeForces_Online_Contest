#include <stdio.h>
using namespace std;
int main()
{
    char in[ 110 ];
    int r, c;
    while(~scanf("%d %d", &r, &c))
    {
        getchar();
        for(int i = 0; i < r; i++)
        {
            gets( in );
            for(int j = 0; j < c; j++)
                if(in[ j ] != '-')
                if((i + j) & 1) in[ j ] = 'W';
                else in[ j ] = 'B';
            puts( in );
        }
    }
    return 0;
}
