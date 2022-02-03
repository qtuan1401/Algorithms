#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;
int q,n;
int p[maxn];
long long f[maxn],s[maxn];
void solve()
{
    n=1000000;
    for(int j=2; j<=n; j++) p[j]=j;
    for(int i=2; i<=n; i++)
        if(p[i]==i)
            for(int j=i; j<=n; j+=i)
                p[j]-=p[j]/i;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j+=i)
            f[j]+=(long long)i*p[j/i];
    for(int j=1; j<=n; j++)
        s[j]=s[j-1]+f[j];
}
int main()
{
    //freopen("test.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    while(cin >> n)
    {
        if (n == 0)
            return 0;
        cout<<s[n]<<"\n";
    }
}