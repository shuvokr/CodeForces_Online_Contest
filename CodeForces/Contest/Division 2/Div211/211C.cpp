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

char in[ 200005 ], cpy[ 200005 ];

int main()
{
    gets( in );
    int len = strlen( in ), i, cou = 0;
    char ch;
    for(i = 0; i < len; i++)
    {
        if(in[ i ] == in[i + 1] && in[ i ] == in[i + 2])
        {
            cpy[ cou++ ] = in[ i ];
            cpy[ cou++ ] = in[ i ];
            i = i + 2;
            ch = in[ i ];
            while(in[ i ] == ch) i++;
            i--;
        }
        else cpy[ cou++ ] = in[ i ];
    }
    //aabccddeeffgggggghhiiiiijjjkkllmmnnooaa
    memset(in, 0, sizeof in);
    len = cou; int k = 0;
    for(i = 0; i < len; i++)
    {
        if(cpy[ i ] == cpy[i + 1] && cpy[i + 2] == cpy[i + 3] && i + 3 < len)
        {
            in[ k++ ] = cpy[ i ]; in[ k++ ] = cpy[ i ];
            in[ k++ ] = cpy[i + 3]; i = i + 3;
        }
        else in[ k++ ] = cpy[ i ];
    }
    puts( in );
    return 0;
}
