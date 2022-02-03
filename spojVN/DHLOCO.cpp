#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
struct matrix
{
    int a[4][4];
}res;
int m;
ll n;
matrix operator*(matrix a,matrix b)
{
    matrix c;
    forr(i,1,3)
        forr(j,1,3)
        {
            c.a[i][j]=0;
            forr(k,1,3)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%m;
        }
    return c;
}
inline matrix calc(matrix a,ll n)
{
    if (n==1)
        return a;
    matrix tmp=calc(a,n/2);
    if (n&1)
        return (tmp*tmp*a);
    else
        return (tmp*tmp);
}
main()
{
    scanf("%lld%d",&n,&m);
    res.a[1][1]=0;res.a[1][2]=1;res.a[1][3]=0;
    res.a[2][1]=0;res.a[2][2]=0;res.a[2][3]=1;
    res.a[3][1]=1;res.a[3][2]=1;res.a[3][3]=1;
    matrix r=calc(res,n);
    printf("%d",r.a[3][3]);
}
