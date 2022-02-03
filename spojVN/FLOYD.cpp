#include <bits/stdc++.h>

using namespace std;
#define maxC 2e4
int n,m,k,u,v,r,t,z,s,f,c[10000][10000],d[1000000],trace[1000000],a[1000000];
bool Free[1000000];
main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for( int i=1;i<=n;i++)
        for( int j=1;j<=n;j++)
            c[i][j]=maxC;
    for( int i=0;i<m;i++)
    {
        cin >> u >> v >> z;
        c[u][v]=z;
        c[v][u]=z;
    }
    while(k--)
    {
        cin >> t >> s >> f;
        for( int i=1;i<=n;i++) Free[i]=true;
        //for( int i=1;i<=n;i++) trace[i]=0;
        for( int i=1;i<=n;i++) d[i]=maxC;
        d[s]=0;
        do
        {
            int Min=maxC;
            u=0;
            for( int i=1;i<=n;i++)
                if (Free[i] && d[i]<Min)
                {
                    Min=d[i];
                    u=i;
                }
            if (u==0 || u==f) break;
            Free[u]=false;
            for( int v=1;v<=n;v++)
                if (Free[v] && d[v]>d[u]+c[u][v])
                {
                    d[v]=d[u]+c[u][v];
                    trace[v]=u;
                }
            }while (true);
             if (!t) cout << d[f];
            else
            {
                r=0;
                while (f!=s)
                {
                    r++;
                    a[r]=f;
                    f=trace[f];
                }
                r++;
                a[r]=s;
                cout << r << " ";
                for(int i=r;i>=1;i--) cout << a[i] << " ";
            }
            cout << "\n";
    }
}
