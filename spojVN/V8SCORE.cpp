#include <bits/stdc++.h>
#define forr(i,a,b) for(long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long i=(b);i>=(a);i--)
using namespace std;
#define fi "v8score.inp"
#define fo "v8score.out"
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
long a[200][200],x[200],n,s,k,sum;
void Print()
{
    cout << "YES"<<endl;
    forr(i,1,k) cout << x[i] << " ";
}
void Try(int i)
{
    forr(j,1,n)
        if (a[j][i]>=x[i-1] && (s-sum)/(k-i+1)>=a[j][i])
        {
            x[i]=a[j][i];
            sum+=x[i];
            if (s==sum && i==k)
            {
                Print();
                exit(0);
            }
            else Try(i+1);
            sum-=x[i];
        }
}
int main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    cin >> s >> k >> n;
    forr(i,1,n)
        forr(j,1,k) cin >> a[i][j];
    Memset(x,0);
    sum=0;
    Try(1);
    cout << "NO";
    return 0;
}

