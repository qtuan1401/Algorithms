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
ll a[25001],b[25001],dp[25001],n;
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> n;
    forr(i,1,n-1) cin >> a[i];
    dp[1]=0;
    dp[2]=a[1];
    dp[3]=a[1]+a[2];
    forr(i,4,n) dp[i]=min(dp[i-1],dp[i-2])+a[i-1];
    cout << dp[n];
}

