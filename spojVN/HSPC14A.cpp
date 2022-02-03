#include <bits/stdc++.h>
using namespace std;
int t,res,n,val=0;
inline int gcd(int x,int y)
{
    while (y!=0)
    {
        int r=x%y;
        val+=x/y-(y==1);
        x=y;
        y=r;
    }
    return x;
}
main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        res=n-1;
        for(int i=n/2;i<n;i++)
        {
            val=0;
            if (gcd(n,i)==1)
                res=min(res,val);
        }
        printf("%d\n",res);
    }
}
 