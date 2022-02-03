#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define md int(3e2+1)
int res,f[md][md][md],n,m,a[md];
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d",&n);
    REP(i,n)
        scanf("%d",&a[i]);
    FOR(k,2,n)
    {
        REP(i,k-1)
            FOR(j,k,n)
            {
                if (a[i]<a[j])
                    f[k][i][j]=max(f[k][i-1][j-1]+1,f[k][i][j]);
                else
                    f[k][i][j]=max(f[k][i-1][j],f[k][i][j-1]);
                res=max(res,f[k][i][j]);
            }
    }
    printf("%d",res);
}
