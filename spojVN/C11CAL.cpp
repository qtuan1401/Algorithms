#include <bits/stdc++.h>
#define md 55
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define base int(1e9+7)
struct matrix
{
    int a[md][md];
    matrix ()
    {
    	memset(a,0,sizeof(a));
    }
}res;
int k,n;
matrix operator * (matrix a,matrix b)
{
    matrix c;
    forr(i,0,k+1)
        forr(j,0,k+1)
            forr(x,0,k+1)
                c.a[i][j]=(c.a[i][j]+(long long)(a.a[i][x])*b.a[x][j]%base)%base;
    return c;
}
inline matrix calc(matrix a,int n)
{
    if (n==1)
        return a;
    matrix tmp=calc(a,n/2);
    if (n&1)
        return tmp*tmp*a;
    else return tmp*tmp;
}
int c[md][md];
main()
{
    forr(i,0,50)
        c[i][0]=1;
    forr(i,1,50)
        forr(j,1,50)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%base;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        forr(i,0,k)
            forr(j,0,i)
                res.a[i][j]=c[i][j];
        forr(i,0,k)
            res.a[k+1][i]=res.a[k][i];
        res.a[k+1][k+1]=1;
        matrix r=calc(res,n);
        printf("%d\n",r.a[k+1][0]);
    }
}
