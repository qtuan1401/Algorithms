#include <bits/stdc++.h>
using namespace std;
#define md 20
long long Pow[md];
int base[md],n,m,r;
vector<int> adj,adj1;
inline void change(int m)
{
    //cout << m;
    while(m)
    {
       // cout << m%3 << " ";
      // cout << m << " ";
        base[++r]=m%3;
        m/=3;
    }
    //for(int i=1;i<=r;i++)
      //  cout << base[i] << " ";
}
inline void solve()
{
    for(int i=1;i<=19;i++)
    {
        //cout << base[i] << " ";
        if (base[i]>=2)
        {
            if (base[i]==2)
            {
                adj.push_back(i-1);
            }
            base[i]=0;
            base[i+1]++;
         //   cout << i-1 << " ";
        }
        else if (base[i])  adj1.push_back(i-1);
    }
}
main()
{
    scanf("%d",&m);
    Pow[0]=1;
    for(int i=1;i<=19;i++)
        Pow[i]=Pow[i-1]*3;
    change(m);
    solve();
    printf("%d ",adj.size());
    for(int i=0;i<adj.size();i++)
    {
        //cout << adj[i] << " ";
        printf("%lld ",Pow[adj[i]]);
    }
    printf("\n%d ",adj1.size());
    for(int i=0;i<adj1.size();i++)
        printf("%lld ",Pow[adj1[i]]);
}
