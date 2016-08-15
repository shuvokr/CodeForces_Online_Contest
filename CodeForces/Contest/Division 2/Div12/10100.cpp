#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int main()
{
    char in[ 1010 ], *tok;
    map <string, int> mp;
    int kag = 0;
    while( gets(in) )
    {
        mp.clear();
        tok = strtok(in, " ,.-_*#/-+!=");
        while(tok != NULL)
        {
            mp[ tok ]++;
            tok = strtok(NULL, " ,.-_*#/-+!=");
        }
        gets( in ); int res = 0;
        tok = strtok(in, " ,.-_*#/-+!=");
        while(tok != NULL)
        {
            if(mp[ tok ]) res++, mp[ tok ]--;
            tok = strtok(NULL, " ,.-_*#/-+!=");
        }
        if( res ) printf("%2d. Length of longest match: %d\n", ++kag, res);
        else printf("%2d. Blank!\n", ++kag);
    }
    return 0;
}
