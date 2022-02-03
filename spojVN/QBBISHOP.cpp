#include <bits/stdc++.h>
#define nmax 1005

using namespace std;
int n,m,p,q,s,t,dp[nmax][nmax];
bool dd[nmax][nmax],visited[nmax][nmax];
int deltaX[5]={1,1,-1,-1};
int deltaY[5]={1,-1,1,-1};
void bfs()
{
    queue <int> QueueX;
    queue <int> QueueY;
    QueueX.push(p);
    QueueY.push(q);
    visited[p][q]=1;
    while (!QueueX.empty() && ! QueueY.empty())
    {
        int u=QueueX.front();
        int v=QueueY.front();
        QueueX.pop();QueueY.pop();
        for (int i=0;i<4;i++)
        {
            int x=u;
            int y=v;
            while (x>0 && x<=n && y>0 && y<=n && !dd[x][y])
            {
                x+=deltaX[i];
                y+=deltaY[i];

                if (!visited[x][y])
                {
                    dp[x][y]=dp[u][v]+1;
                    QueueX.push(x);
                    QueueY.push(y);
                    visited[x][y]=true;
                }
            }
        }
    }
    if (dp[s][t]==0)
        cout << -1;
    else
    cout << dp[s][t];
}

int main()
{
    //freopen("qbbishop.inp","r",stdin);
    cin >> n >> m >> p >> q >> s >> t;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        dd[u][v]=true;
    }
    bfs();
}
