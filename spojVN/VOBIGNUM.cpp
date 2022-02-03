#include <bits/stdc++.h>

using namespace std;
#define st first
#define nd second
#define rd third
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long lli;
lli mod(string a,lli Mod,int neg)
{
    lli i,hold=0;
    lli n=a.size();
    lli l=0;
    if (neg) l=1;
    for(int i=l;i<n;i++)
        hold=(int(a[i])-48+hold*10)%Mod;
    if (neg) hold=-hold;
    return hold;
}
lli a[1000000],b[1000000],c[1000000],d[1000000];
int n,q;
string s;
lli calc(int i,int j,char c,lli *a,lli Mod)
{
    if (c=='+') return ((a[i]+a[j])%Mod+Mod)%Mod;
    if (c=='-') return ((a[i]-a[j])%Mod+Mod)%Mod;
    if (c=='*') return ((a[i]%Mod*a[j]%Mod)%Mod+Mod)%Mod;
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        int neg=0;
        if (s[0]=='-')
        {
            neg=1;
        }
     //   cout << s << endl;
        a[i]=mod(s,1000000007,neg);
        b[i]=mod(s,2147483647,neg);
        c[i]=mod(s,1073676287,neg);
        d[i]=mod(s,2971215073,neg);
    }
    //for(int i=0;i<n;i++) cout << a[i] << b[i] << c[i] << endl;
    for(int i=0;i<q;i++)
    {
        int a1,b1,d1,e;
        char c1,f;
        cin >> a1 >> b1 >> c1 >> d1 >> e >> f;
        if (calc(a1,b1,c1,a,1000000007)==calc(d1,e,f,a,1000000007) && calc(a1,b1,c1,b,2147483647)==calc(d1,e,f,b,2147483647) && calc(a1,b1,c1,c,1073676287)==calc(d1,e,f,c,1073676287) && calc(a1,b1,c1,d,2971215073)==calc(d1,e,f,d,2971215073)) cout << "YES\n";
        else cout  << "NO\n";
    }
}
