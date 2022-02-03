#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e6)+1
#define INF int(2e9)+7
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
int x[maxN],a[maxN],n,s,l,d;
bool Free[maxN];
void Back(int i,int k)
{
    if (d==1000) return;
    if (i>=l+1)
    {
        forr(i,1,l)
            printf("%d ",x[i]);
        printf("\n");
        d++;
        return;
    }
    if (i>1 && k<s)
        Back(i+1,k+1);
    forr(j,1,n)
        if (!Free[j])
        {
            Free[j]=true;
            forr(z,0,a[j]-1)
                x[i+z]=j;
            Back(i+a[j],k);
            forr(z,0,a[j]-1)
                x[i+z]=0;
            Free[j]=false;
        }
}
main()
{
    scanf("%d%d",&l,&n);
    forr(i,1,n)
        scanf("%d",&a[i]),s+=a[i];
    s=l-s;
    Back(1,0);
}
