#include <bits/stdc++.h>
using namespace std;
#define base 76213
int b[5005],res,n;
main()
{
    scanf("%d",&n);
    if (n==1)
    {
        printf("0");
        exit(0);
    }
    res=0;
    b[n]=n%base;
    for(int i=n-1;i>=1;i--)
        b[i]=(b[i+1]%base*i%base+base)%base;
    for(int i=2;i<=n-1;i++)
    {
        if (i%2==0)
            res=(res%base+b[i+1]%base+base)%base;
        else res=(res%base-b[i+1]%base+base)%base;
    }
    if (n&1)
        res=(res%base-1+base)%base;
    else res=(res%base+1+base)%base;
    printf("%d",res);
}
