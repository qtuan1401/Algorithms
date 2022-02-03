#include <bits/stdc++.h>
using namespace std;
#define md 5*int(1e5)+5
typedef pair<int,int> ii;
int n;
long long pos;
struct node
{
    long long a, b;
} a[md],c[md];
bool check(int mid)
{
  //  if (mid<150) cout << mid << "\n";
    for(int i=1;i<=n;i++)
        c[i]=a[i];
    //for(int i=1;i<=n;i++)
      //  swap(c[i].a,c[i].b);
    for(int i=1;i<n;i++)
    {
        c[i].a=c[i].a-mid;
        if (c[i].a>=0)
            c[i+1].a=c[i+1].a+max(0LL,c[i].a-c[i+1].b+c[i].b);
        else c[i+1].a=c[i+1].a+c[i].a-c[i+1].b+c[i].b;
    }
    if (c[n].a>=mid)
        return true;
    return false;
  //  cout << endl;
}
void bs(int l,int r)
{
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (check(mid))
        {
            pos=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].b,&a[i].a);
  //  sort(a+1,a+1+n);
    bs(1,1000000000);
    printf("%lld",pos);
}
