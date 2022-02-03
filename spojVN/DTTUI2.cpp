#include <bits/stdc++.h>

using namespace std;
int a[10001],b[10001];
int dp[10001][10001];
int n,m,x,y,z,r;
int Pow[11];
int solve(int n){
    int i;
    for(i=0;i<=10;i++)
        if (Pow[i+1]>n) break;
        else{
            r++;
            a[r]=Pow[i]*x;
            b[r]=y*Pow[i];

        }
    //2^n-(2^(n+1)-1)-n
    return Pow[i]-(Pow[i+1]-1-n);
}
main(){
   // freopen("test.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    Pow[0]=1;
    for(int i=1;i<=10;i++) Pow[i]=Pow[i-1]*2;
    for(int i=1;i<=n;i++){
        cin >> x >> y >> z;
        z=solve(z);
        r++;
        a[r]=z*x;
        b[r]=y*z;
    }
 //   for(int i=1;i<=r;i++) cout << a[i] << " " << b[i] << "\n";
    for(int i=1;i<=r;i++){
        for(int j=0;j<=m;j++){
            if (a[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
        }
    }
    cout << dp[r][m];
}
