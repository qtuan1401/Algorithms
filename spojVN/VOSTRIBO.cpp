#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
const long long base=(long long)(1e15+7);
struct matrix
{
    long long a[5][5];
}a;
int n,q;
inline long long mul(long long x, long long a)
{
    if (a==0)
        return 0;
    long long tmp=mul(x,a/2);
    if (a&1)
        return (tmp+tmp+x)%base;
    else
        return (tmp+tmp)%base;
}
matrix operator*(matrix a,matrix b)
{
    matrix c;
    forr(i,1,4)
        forr(j,1,4)
        {
            c.a[i][j]=0;
            forr(k,1,4)
            c.a[i][j]=(c.a[i][j]+mul(a.a[i][k],b.a[k][j]))%base;
        }
    return c;
}
inline matrix calc(matrix a,int n)
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
    //freopen("test.inp","r",stdin);
    int b[]={0,1,2,3,6};
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&n);
        a.a[1][1]=0;a.a[1][2]=1;a.a[1][3]=0;a.a[1][4]=0;
        a.a[2][1]=0;a.a[2][2]=0;a.a[2][3]=1;a.a[2][4]=0;
        a.a[3][1]=1;a.a[3][2]=1;a.a[3][3]=1;a.a[3][4]=0;
        a.a[4][1]=1;a.a[4][2]=1;a.a[4][3]=1;a.a[4][4]=1;
        if (n<=3)
        {
            if (n==1)
                printf("1\n");
            else if (n==2)
                printf("3\n");
            else printf("6\n");
        }
        else
        {
            n-=3;
            matrix r=calc(a,n);
            long long res=0;
            printf("%lld\n",(r.a[4][1]+r.a[4][2]*2+r.a[4][3]*3+r.a[4][4]*6)%base);
        }
    }
}
