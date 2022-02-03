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
ll a[60001],b[60001],dp[60001],n;
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> n;
    forr(i,1,n) cin >> a[i];
    forr(i,1,n-1) cin >> b[i];
    dp[1]=a[1];
    forr(i,2,n) dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i-1]);
    cout << dp[n];
}

