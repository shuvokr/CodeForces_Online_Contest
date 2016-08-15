#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
 
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>
 
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl
 
using namespace std;
 
#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }
 
    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }
 
    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }
 
 
}asdfg;
 
 
 
//Header ends here
 
#define MAXX 501
#define MAXlogN 9
 
int N, Q;
int ara[MAXX][MAXX];
int M[MAXX][MAXX][MAXlogN];
 
 
int main()
{
 
    int kases, kaseno = 0;
    int p, q, s;
 
    take(kases);
 
    while(kases--)
    {
        take(N, Q);
        loop(i, N)
        {
            loop(j, N)
            {
                take(ara[i][j]);
            }
        }
 
 
        for(int k=0; (1<<k)<=N; k++)
        {
            for(int i=0; i+(1<<k)-1 < N; i++)
            {
                for(int j=0; j+(1<<k)-1<N; j++)
                {
                    if(k==0)
                    {
                        M[i][j][k] = ara[i][j];
                    }
                    else
                    {
                        int ad = 1<<(k-1);
                        M[i][j][k] = max( max(M[i][j][k-1], M[i + ad ][j][k-1]), max(M[i][j + ad ][k-1], M[i +ad][j+ ad][k-1]  ) );
 
                        // max( max(ara[i][j][k-1], ara[i + (1<<(k-1)) ][j][k-1]), max(ara[i][j + (1<<(k-1)) ][k-1], ara[i +(1<<(k-1))][j+ (1<<(k-1))][k-1]  ) );
                    }
                }
            }
        }
 
 
        pf("Case %d:\n", ++kaseno);
 
        loop(i, Q)
        {
            take(p, q, s);
            int k = log2(s);
            int ad = 1<<k;
            p--; q--;
            int result = max( max(M[p][q][k], M[p+s-ad][q][k]), max(M[p][q+s-ad][k], M[p+s-ad][q+s-ad][k])  );
            pf("%d\n", result);
        }
 
 
 
 
    }
 
}
