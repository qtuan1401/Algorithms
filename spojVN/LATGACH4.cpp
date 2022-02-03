#include <bits/stdc++.h>
using namespace std;
struct matrix
{
    long long a[3][3];
}a,b,c;
int q;
const int base=111539786;
inline matrix mul(matrix a,matrix b)
{
    c.a[1][1]=(a.a[1][1]*b.a[1][1]+a.a[1][2]*b.a[2][1])%base;
    c.a[1][2]=(a.a[1][1]*b.a[1][2]+a.a[1][2]*b.a[2][2])%base;
    c.a[2][1]=(a.a[2][1]*b.a[1][1]+a.a[2][2]*b.a[2][1])%base;
    c.a[2][2]=(a.a[2][1]*b.a[1][2]+a.a[2][2]*b.a[2][2])%base;
    return c;
}
inline matrix calc(matrix a,int n)
{
    if (n==1)
        return a;
    matrix tmp=calc(a,n/2);
    tmp=mul(tmp,tmp);
    if (n%2==1)
        return mul(tmp,a);
    else
        return tmp;
}
inline long long solve(int x)
{
    matrix a,f;
    if (x<=2)
        return 1;
    a.a[1][1]=0;
    a.a[1][2]=a.a[2][1]=a.a[2][2]=1;
    f=calc(a,x);
    return (f.a[2][1]);
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&q);
    while (q--)
    {
        int x;
        scanf("%d",&x);
        x++;
        printf("%lld\n",solve(x));
    }
}
