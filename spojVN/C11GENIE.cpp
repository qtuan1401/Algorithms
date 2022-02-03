#include  <bits/stdc++.h>
using namespace std;
#define md int(1e7)+5
bool dd[md];
int a[md],n,r;
long long c[md],res;
const int base=int(1e9)+7;
main()
{
//    freopen("test.inp.txt","r",stdin);
    scanf("%d",&n);
    dd[1]=true;
    for(int i=2;i<=n/2;i++)
        if (!dd[i])
            for(int j=2;j<=n/i;j++)
                dd[i*j]=true;
    for(int i=2;i<=n;i++)
        if (!dd[i])
            a[++r]=i;
    res=1;
    for(int i=1;i<=r;i++)
    {
        long long x=a[i];
        while (n>=x)
        {
            c[i]+=n/x;
            x*=a[i];
        }
    }
    for(int i=1;i<=n;i++)
        if (c[i]%2==1)
            c[i]--;
    //for(int i=1;i<=r;i++)
      //  cout << c[i] << " ";
//    for(int i=1;i<=r;i++)
//      c[i]/=2;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c[i];j++)
            res=(res*a[i])%base;
   // res=(res%base*(res%base))%base;
    printf("%lld",res);
}
