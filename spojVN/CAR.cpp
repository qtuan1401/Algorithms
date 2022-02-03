#include <bits/stdc++.h>
using namespace std;
long long res;
#define md 10005
int a[md],b[md],n;
long long d[md];
struct node
{
    int a,b,c;
} c[md];
bool operator<(node a,node b)
{
    return (a.a*b.b>a.b*b.a);
}
main()
{
//    freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i].a);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i].b);
    for(int i=1;i<=n;i++)
        c[i].c=i;
    sort(c+1,c+1+n);
  //  for(int i=1;i<=n;i++)
    //    cout << c[i].a << " " <<c[i].b << "\n";
    for(int i=1;i<=n;i++)
        d[i]=d[i-1]+c[i].b;
    for(int i=1;i<=n;i++)
        res+=c[i].a*d[i];
    printf("%lld\n",res);
    for(int i=1;i<=n;i++)
        printf("%d ",c[i].c);
}

