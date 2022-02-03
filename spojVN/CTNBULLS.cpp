#include <bits/stdc++.h>
using namespace std;
#define base 2111992
#define md 100005
int f[md],n,k;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k+1;i++)
        f[i]=(i+1)%base;
    for(int i=k+2;i<=n;i++)
        f[i]=(f[i-1]+f[i-k-1])%base;
    printf("%d",f[n]);
}
