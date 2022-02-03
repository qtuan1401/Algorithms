#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e4)+1
#define INF int(1e9)+1
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
int dp[maxN],d[maxN][maxN],a[maxN][maxN],n,m;
inline bool check(int a,int b)
{
    forr(i,2,m)
        if (d[i][a]>d[i][b])
            return false;
    return true;
}
main()
{
  //  freopen(fi,"r",stdin);
  //  freopen(fo,"w",stdout);
    scanf("%d%d",&n,&m);
    int res=0;
    forr(i,1,m)
        forr(j,1,n)
        {
            scanf("%d",&a[i][j]);
            d[i][a[i][j]]=j;
        }
    forr(i,1,n)
    {
        dp[a[1][i]]=1;
        forr(j,1,i-1)
            if (check(a[1][j],a[1][i]))
                dp[a[1][i]]=max(dp[a[1][j]]+1,dp[a[1][i]]);
        res=max(res,dp[a[1][i]]);
    }
    printf("%d",res);
}
