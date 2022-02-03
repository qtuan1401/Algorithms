#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
#define maxn 1010
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
int n , m , a[maxn][maxn],h[maxn],l[maxn],r[maxn],res;
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    scanf("%d %d",&m,&n);
    forr(i,1,m)
        forr(j,1,n) scanf("%d",&a[i][j]);
    h[0]=h[n+1]=-1;
    forr(i,1,m)
    {
        forr(j,1,n) h[j]=a[i][j]*(h[j]+1);
        forr(j,1,n)
        {
            l[j]=j;
            while (h[l[j]-1]>=h[j]) l[j]=l[l[j]-1];
        }
        forl(j,1,n)
        {
            r[j]=j;
            while (h[r[j]+1]>=h[j]) r[j]=r[r[j]+1];
        }
        forr(j,1,n) res=max(res,h[j]*(r[j]-l[j]+1));
    }
    printf("%d",res);
}

