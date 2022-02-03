#include <bits/stdc++.h>
#define task ""
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
int a[maxN],dp[3][maxN],n,m,id;
main()
{
   // freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    scanf("%d%d",&n,&m);
    swap(n,m);
    forr(i,1,n)
    {
        id=1-id;
        dp[id][0]=dp[id][m+1]=INF;
        forr(j,1,m)
        {
            scanf("%d",&a[j]);
            dp[id][j]=min(dp[1-id][j],dp[id][j-1])+a[j];
        }
        forl(j,m,1)
            dp[id][j]=min(dp[id][j],dp[id][j+1]+a[j]);
    }
    int res=INF;
    forr(i,1,m)
        if (dp[id][i])
        	res=min(res,dp[id][i]);
    printf("%d",res);
}
