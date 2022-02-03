#include <bits/stdc++.h>
#define maxN 30010
using namespace std;
struct node
{
    int x,y,y2,type;
};
struct tree
{
    int len,type;
};
node a[maxN];
tree val[8*maxN];
int n,x1,x2,y,y2,pre_x;
bool cmp(const node u,const node v)
{
    return (u.x<v.x || (u.x==v.x && u.type<v.type));
}
void update(int i,int u,int v,int l,int r,int t)
{
    if (v<l || u>r)
        return;
    if (l<=u && v<=r)
    {
        val[i].type+=t;
        if (t==1)
            val[i].len=(v-u+1);
        else
        {
            if (val[i].type==0)
                val[i].len=val[i*2].len+val[i*2+1].len;
        }
        return;
    }
    int mid=(u+v)/2;
    update(i*2,u,mid,l,r,t);
    update(i*2+1,mid+1,v,l,r,t);
    if (val[i].type==0)
        val[i].len=val[i*2].len+val[i*2+1].len;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i+=2)
    {
        scanf("%d%d%d%d",&x1,&y,&x2,&y2);
        a[i].x=x1;
        a[i+1].x=x2;
        a[i].type=1;
        a[i+1].type=-1;
        a[i].y=a[i+1].y=y;
        a[i].y2=a[i+1].y2=y2;
    }
    n*=2;
    long long res=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        res+=(a[i].x-pre_x)*val[1].len;
        pre_x=a[i].x;
        update(1,0,maxN,a[i].y,a[i].y2-1,a[i].type);
    }
    printf("%lld",res);
}
