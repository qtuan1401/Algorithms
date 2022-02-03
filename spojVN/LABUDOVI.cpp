#include <bits/stdc++.h>
using namespace std;
int deltaX[]={0,0,1,-1};
int deltaY[]={-1,1,0,0};
#define md 1505
#define INF int(1e9)
typedef pair<int,int> ii;
int d[md][md];
ii q[md*md+1];
int n,m,r,res;
bool vis[md][md];
char a[md][md];
ii s,t;
int s1,s2,t1,t2;
inline void bfs()
{
    for(int i=1;i<=r;i++)
        d[q[i].first][q[i].second]=0;
    int c=0;
    do
    {
        c++;
        ii val=q[c];
        int u=val.first;
        int v=val.second;
        for(int i=0;i<4;i++)
        {
            int uu=u+deltaX[i];
            int vv=v+deltaY[i];
            if (uu<1 || uu>n || vv<1 || vv>m)
                continue;
            if (d[uu][vv]>d[u][v]+1)
            {
                d[uu][vv]=d[u][v]+1;
                r++;
                q[r]=ii(uu,vv);
            }
        }
    }while(c!=r);
}
int f[md][md];
int ll[2],rr[2];
ii qq[3][md*md];
inline void solve(int x,int y)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=INF;
 //   memset(qq,0,sizeof(qq));
    int id=0;
    ll[id]=0;
    rr[id]=1;
    qq[id][1]=ii(x,y);
 //   cout << "8";
    f[x][y]=0;
  //  cout << "8";
    int kind=0;
   // cout << "8";
    do
    {
     //   cout << "8";
        if (ll[id]==rr[id])
        {
            ll[id]=0;
            rr[id]=0;
            id=1-id;
        }
        ll[id]++;
        ii val=qq[id][ll[id]];
      //  cout << ll[id] << " " <<val.first <<  " "<<val.second << endl;
        int u=val.first;
        int v=val.second;
        //cout << u << " "<<v <<endl;
        for(int i=0;i<4;i++)
        {
            int uu=u+deltaX[i];
            int vv=v+deltaY[i];
           // cout << uu << " "<<vv <<endl;
            if (uu<1 || uu >n || vv<1 || vv> m)
                continue;
            if (f[uu][vv]>max(f[u][v],d[uu][vv]))
            {
                f[uu][vv]=max(f[u][v],d[uu][vv]);
        //        cout << f[uu][vv] <<endl;
                if (f[uu][vv]==f[u][v])
                    kind=id;
                else kind=1-id;
                rr[kind]++;
                qq[kind][rr[kind]]=ii(uu,vv);
            }
        }
      //  cout << ll[0] << " "<<rr[0] << " "<<rr[1] << " "<<ll[1] <<endl;
    }while ((ll[0]-rr[0])+(ll[1]-rr[1])!=0);
    printf("%d",f[t1][t2]);
}
main()
{
//    freopen("test.inp.txt","r",stdin);
    scanf("%d%d",&n,&m);
    r=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=INF;
    int c=0,s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
        for(int j=1;j<=m;j++)
            if (a[i][j]!='X')
            {
                q[r++]=ii(i,j);
                d[i][j]=0;
                if (a[i][j]=='L')
                {
                    if (s1==0 && s2==0)
                    {
                        s1=i;
                        s2=j;
                    }
                    else
                    {
                        //t=ii(i,j);
                        t1=i;
                        t2=j;
                    }
                }
            }
    }
   // cout << s.first << " "<<s.second << " "<< f.first <<" "<<f.second<<endl;
    r--;
    //cout << s1 << " " <<s2 << " " << t1 << " "<<t2 <<endl;
 //   for(int i=1;i<=r;i++)
        bfs();
   /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout << d[i][j] << " ";
        cout <<endl;
    }*/
    solve(s1,s2);
}
