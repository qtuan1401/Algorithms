#include <bits/stdc++.h>

using namespace std;
#define maxN 2001
typedef pair<int,int> ii;
queue<ii> Queue;
bool checkX[maxN],checkY[maxN],dd[maxN][maxN];
int MaxX[maxN],MinX[maxN],MaxY[maxN],MinY[maxN],res,n;
void bfs()
{
    while(!Queue.empty())
    {
        res++;
        int u=Queue.front().first;
        int v=Queue.front().second;
        Queue.pop();
        //solve(checkX,MaxX,MinX,u,v);
        //solve(checkY,MaxY,MinY,v,u);
        if (!checkX[u])
        {
            checkX[u]=true;
            MaxX[u]=MinX[u]=v;
        }
        else
        {
            if (v<MinX[u])
            {
                for(int x=v+1;x<MinX[u];x++)
                    if (!dd[u][x])
                    {
                        dd[u][x]=true;
                        Queue.push(ii(u,x));
                    }
                MinX[u]=v;
            }
            if (v>MaxX[u])
            {
                for(int x=MaxX[u]+1;x<v;x++)
                    if (!dd[u][x])
                    {
                        dd[u][x]=true;
                        Queue.push(ii(u,x));
                    }
                MaxX[u]=v;
            }
        }
        if (!checkY[v])
        {
            checkY[v]=true;
            MaxY[v]=MinY[v]=u;
        }
        else
        {
            if (u<MinY[v])
            {
                for(int x=u+1;x<MinY[v];x++)
                    if (!dd[x][v])
                    {
                        dd[x][v]=true;
                        Queue.push(ii(x,v));
                    }
                MinY[v]=u;
            }
            if (u>MaxY[v])
            {
                for(int x=MaxY[v]+1;x<u;x++)
                    if (!dd[x][v])
                    {
                        dd[x][v]=true;
                        Queue.push(ii(x,v));
                    }
                MaxY[v]=u;
            }
        }
    }
}
main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        u+=1000;
        v+=1000;
        if (!dd[u][v])
        {
            Queue.push(ii(u,v));
            dd[u][v]=true;
        }
    }
    bfs();
    cout << res;
}
