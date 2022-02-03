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
long a[10000],n,Max,dp[10000];
bool bs(int k,int l,int r)
{
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid]==k) return true;
        if (a[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return false;
}
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> n;
    forr(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    forr(i,1,n)
        forr(j,1,i-1)
            if (bs(a[i]-a[j],1,j-1)) dp[i]=max(dp[i],dp[j]+1);
    Max=dp[1];
    forr(i,2,n)
        if (Max<dp[i]) Max=dp[i];
  //  forr(i,1,n) cout << dp[i] << " ";
    cout << Max+1;
}

