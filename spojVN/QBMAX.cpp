#include <iostream>

using namespace std;

int m,n,i,j,resmax;
int a[301][301],f[301][301];

int main()
{
    cin >> m >> n;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            cin >> a[i][j];
    for (j=0;j<=n+1;j++)
    {
        f[0][j]=-10000001;
        f[m+1][j]=-1000001;
    }
    for (i=1;i<=m;i++) f[i][1]=a[i][1];
    for (j=2;j<=n;j++)
        for (i=1;i<=m;i++)
            f[i][j]=max(f[i-1][j-1],max(f[i][j-1],f[i+1][j-1]))+a[i][j];
    resmax=-10000001;
    for (i=1;i<=m;i++)
        resmax=max(resmax,f[i][n]);
    cout << resmax;
    return 0;
}
