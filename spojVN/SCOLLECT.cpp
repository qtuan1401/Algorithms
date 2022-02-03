#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(b);i>=(a);i--)
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
int dp[128*2][129][129],n,m,a[200][200];
char c;
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> m >> n;
    forr(i,0,n)
        forr(j,0,m) a[i][j]=INT_MIN;
    forr(i,1,n)
        forr(j,1,m)
        {
            cin >> c;
            if (c=='*') a[i][j]=1;
            else if (c=='.') a[i][j]=0;
        }
    forr(i,0,m+n-2)
        forr(j1,0,n)
            forr(j2,0,n) dp[i][j1][j2]=INT_MIN;
    dp[0][1][1]=a[1][1];
    forr(i,1,m+n-2)
        forr(j1,1,n)
            forr(j2,1,n)
                if (i-j2+2>=0 && i-j2+2<=m && i-j1+2<=m && i-j1+2>=0 && a[j2][i-j2+2]!=INT_MIN && a[j1][i-j1+2]!=INT_MIN)
                {
                    dp[i][j1][j2]=max(dp[i][j1][j2],max(max(dp[i-1][j1][j2],dp[i-1][j1-1][j2]),max(dp[i-1][j1][j2-1],dp[i-1][j1-1][j2-1])))+a[j1][i-j1+2]+a[j2][i-j2+2];
                    if (j1==j2) dp[i][j1][j2]-=a[j1][i-j1+2];
                }
    if (dp[n+m-2][n][n]<=0) cout << 0;
    else cout<< dp[n+m-2][n][n];
}

