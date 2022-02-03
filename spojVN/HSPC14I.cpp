#include <bits/stdc++.h>
using namespace std;
int a,b,c;
main()
{
    while (scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        printf("%d\n",max(0,max(c-(b+1),(b-(a+1)))));
    }
}
