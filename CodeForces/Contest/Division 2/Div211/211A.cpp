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
    string str[ 10 ];
    str[ 0 ] = "O-|-OOOO";
    str[ 1 ] = "O-|O-OOO";
    str[ 2 ] = "O-|OO-OO";
    str[ 3 ] = "O-|OOO-O";
    str[ 4 ] = "O-|OOOO-";

    str[ 5 ] = "-O|-OOOO";
    str[ 6 ] = "-O|O-OOO";
    str[ 7 ] = "-O|OO-OO";
    str[ 8 ] = "-O|OOO-O";
    str[ 9 ] = "-O|OOOO-";
    int num, n;
    scanf("%d", &n);
    num = n % 10;
    n = n / 10;
    cout << str[ num ] << endl;
    while( n )
    {
        num = n % 10;
        n = n / 10;
        cout << str[ num ] << endl;
    }
    return 0;
}
