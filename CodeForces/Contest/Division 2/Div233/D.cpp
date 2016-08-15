#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <string>
#include <sstream>
#include <list>
 
using namespace std;
 
#define fst first
#define snd second
#define EPS 1e-7
#define PI 2*acos(0.0)
#define inf (1<<29)
#define akbarbe ceil
#define akkombe floor
#define bug(x) cout<<#x<<" = "<<x<<endl
#define N 1000000
#define LL long long
#define delect(str) str.erase(std::remove_if(str.begin(), str.end(), str[i]), str.end());
 
int x[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int y[] = {0, -1, 1, 0, 1, -1, 1, -1};
 
int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1};
 
 
int main()
{
 
    int v,c;
    //freopen("input.txt","r",stdin);
    while(cin>>v>>c)
    {
        string s;
        vector<string> vv,p;
        for(int i=0; i<v; i++)
        {
            cin>>s;
            vv.push_back(s);
        }
        for(int i=0; i<c; i++)
        {
            cin>>s;
            p.push_back(s);
        }
        int cc =0;
        for(int i=0; i<p.size(); i++)
        {
            string x = p[i];
            map<char,int>mp1,mp2;
            map<char,int>::iterator it1,it2; set<char>st;
            for(int ii=0; ii<x.size(); ii++){
                mp1[x[ii]]++; st.insert(x[ii]);
                }
            for(int j=0; j<vv.size(); j++)
            {
                string y=vv[j];
                //cout<<"y="<<y<<endl<<"x="<<x<<endl;
                for(int jj=0; jj<y.size(); jj++) mp2[y[jj]]++;
                int cnt=0;
                for(it1 = mp2.begin(); it1!=mp2.end(); it1++)
                {
                    for(it2 = mp1.begin(); it2!=mp1.end(); it2++)
                    {
                        if(it1->fst==it2->fst)
                        {
                            if(it1->snd>=it2->snd)
                            {
                                cnt++;
 
                            }
 
                        }
                    }
 
                }
                if(cnt==st.size())
                {
                    cc++;
                    //cout<<vv[j]<<endl;
                    vv[j]="*";
                    break;
                }
 
 
            }
        }
        cout<<cc<<endl;
    }
    return 0;
}
