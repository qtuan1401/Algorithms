#include <bits/stdc++.h>
using namespace std;
string dp[5001][101];
int n;
string operator +(string a, string b)
{
    for(int i=a.length();i<=b.length()-1;i++) a = '0' + a;
    for(int i=b.length();i<=a.length()-1;i++) b = '0' + b;
    string c = a;
    int nho = 0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp = (a[i] - '0') + (b[i] - '0') + nho;
        c[i] = (tmp % 10 + '0');
        nho = tmp / 10;
    }
    if (nho) c = '1' + c;
    return c;
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<=n+2;i++)
        for(int j=0;j<=100;j++)
            dp[i][j]="0";
    dp[0][0]="1";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=trunc(sqrt(i*2))+1;j++)
            if (1LL*j*(j+1)<=2*i)
             dp[i][j]=dp[i-j][j]+dp[i-j][j-1];
    string res="0";
    for(int i=2;i<=trunc(sqrt(n*2))+1;i++)
        res=res+dp[n][i];
    cout <<res;
}
