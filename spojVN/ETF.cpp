#include <bits/stdc++.h>
using namespace std;
long t,i,n,res;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);res=n;
        for(i=2;i<=trunc(sqrt(n));i++)
        if (n%i==0)
        {
            while (n%i==0) n/=i;
            res-=res/i;
        }
        if (n>1) res-=res/n;
        printf("%d\n",res);
    }
    return 0;
}
