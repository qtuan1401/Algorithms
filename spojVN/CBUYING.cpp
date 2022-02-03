#include <bits/stdc++.h>
using namespace std;
const int md=int(1e5)+1;
typedef unsigned long long int ll;
struct node
{
    long long p,c;
} a[md];
bool operator<(node a,node b)
{
    return (a.p<b.p);
}
ll b;
int n;
ll Count;
main()
{
    scanf("%d%lld",&n,&b);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].p,&a[i].c);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if (b>=a[i].p*a[i].c)
        {
            b-=a[i].p*a[i].c;
            Count+=a[i].c;
        }
        else
        {
            Count+=b/a[i].p;
            break;
        }
    printf("%lld",Count);
}
