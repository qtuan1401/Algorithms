#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+5
int a[md],n;
long long f[md],f1[md];
main()
{
   // freopen("test.inp","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        f[i]=max(f1[i-1]+a[i],f[i-1]);
        f1[i]=max(f[i-1]-a[i],f1[i-1]);
    }
    printf("%lld",max(f[n],f1[n]));
}
