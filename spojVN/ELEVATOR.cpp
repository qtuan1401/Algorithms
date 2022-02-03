#include <bits/stdc++.h>
using namespace std;
#define md 40001
struct node
{
    int h,a,c;
} a[md];
bool operator<(node a,node b)
{
    return a.a<b.a;
}
bool f[2][md];
int n,s;
main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d",&n);
   // cout << n;
    s=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].h,&a[i].a,&a[i].c);
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++)
      //  cout << a[i].h << " "<<a[i].a << " "<<a[i].c <<"\n";
    int x=0,y=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].c;j++)
            for(int k=1;k<=a[i].a;k++)
            {
                int t=k-a[i].h*j;
                f[y][k]=f[y][k] | f[x][k] | (t==0) | ((t>0) & f[x][t]);
            }
        x=1-x;
        y=1-y;
    }
    for(int i=a[n].a;i>=1;i--)
        if (f[x][i])
        {
            printf("%d",i);
            exit(0);
        }
    printf("0");
}
