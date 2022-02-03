#include <bits/stdc++.h>
#define forr(i,a,b) for(long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
ll n,k,m,dp[100000];
bool dd[100000];
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> n >> k;
    forr(i,1,k)
    {
        cin >> m;
        dd[m]=true;
    }
    dp[1]=1;
    forr(i,2,n)
        if (dd[i]) dp[i]=0;
        else dp[i]=(dp[i-1]+dp[i-2])%14062008;
    cout << dp[n];
}

