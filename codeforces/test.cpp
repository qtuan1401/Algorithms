#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve()
{
 
int n;
cin >> n;
vector<long long> dp1(n+2,0),dp2(n+2,0);
dp1[0]=1;
while(n--)
{
    int x;
    cin >> x;
    dp1[x+1] +=dp1[x+1];
    dp1[x+1] +=dp1[x];
    if (x) dp2[x-1]+=dp2[x-1];
    if (x) dp2[x-1]+=dp1[x-1];
    dp2[x+1]+=dp2[x+1];
 
    dp1[x+1]%=MOD;
    if(x)dp2[x-1]%=MOD;
    dp2[x+1]%=MOD;
}
long long rs=-1;
for (int x:dp1) rs+=x;
for (int x:dp2) rs+=x;
cout << rs%MOD << "\n";
 
}
 
int main()
{
  freopen("test.in","r",stdin);
int t=1;
cin >> t;
while(t--) solve();
 
}