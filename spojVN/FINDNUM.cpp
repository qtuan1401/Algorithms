#include <bits/stdc++.h>
#define forr(i,a,b) for(long long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long long i=(b);i>=(a);i--)
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
ll n;
ll a[]={2,3,5,7,11,13,17,19,23,29};
ll res;
ll Power(ll i, ll k)
{
    if(k==1) return a[i];
    ll tmp=Power(i,k/2);
    if (k%2==0) return tmp*tmp;
    return tmp*tmp*a[i];
}

void Try(ll n, ll i, ll m)
{
    if(n==1)
    {
        res=min(res,m);
        return;
    }
    forr(k,2,n)
    {
        if(n%k==0)
        {
            ll p=Power(i,k-1);
            if(p>0 && m<res/p)
            {
                m*=p;
                Try(n/k,i+1,m);
                m/=p;
            }
        }
    }
}
int main()
{
    cin>>n;
    res=LONG_LONG_MAX;
    Try(n,0,1);
    cout<<res;
}
