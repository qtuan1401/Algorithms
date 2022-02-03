#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
int r,Max,b[30000],a[10000],vt,m,i,j,n;
bool kt[10000];
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    scanf("%d %d",&n,&m);
    forr(i,1,n)
    {
        scanf("%d",&a[i]);
        kt[a[i]]=true;
    }
    sort(a+1,a+1+n);
    if (a[n]+a[n-1]+a[n-2]<=m)
    {
        printf("%d",a[n]+a[n-1]+a[n-2]);
        exit(0);
    }
    b[a[1]]=a[1];
    forr(i,a[1]+1,30000)
        if (kt[i]) b[i]=i;
        else b[i]=b[i-1];
  //  forr(i,1,20) cout << b[i] << " ";
    Max=a[1]+a[2]+a[3];
    forr(i,1,n-2)
        forr(j,i+1,n-1)
        {
         vt=m-a[i]-a[j];//cout << b[m-a[i]-a[j]] << " "  << a[i] << " " << a[j] << " ";
        if ((vt>0) && (vt!=a[i]) && (vt!=a[j]) &&(b[m-a[i]-a[j]]))
        {
            Max=max(b[m-a[i]-a[j]]+a[i]+a[j],Max);
           // cout << b[m-a[i]-a[j]]  << " " << a[i] << " " << a[j]<< endl;
        }
        }
    printf("%d",Max);
}

