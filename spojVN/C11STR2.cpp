#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll base=1000000000+7;
string a,b;
ll ha[100005],hb[100005],Pow[100005];
long n,m;
bool check(long x)
{
     ll xa,xb;
     long n=a.size()-1;
     xb=hb[x];
     xa=(ha[n]-ha[n-x]*Pow[x]+base*base)%base;
     if (xa==xb) return 1;
     else return 0;
}
int main(){
    getline(cin,a);
    a='#'+a;
    getline(cin,b);
    b='#'+b;
    Pow[0]=1;
    for(long i=1;i<a.size();i++)
        Pow[i]=Pow[i-1]*26 % base;
    ha[0]=0;
    for (long i=1;i<a.size();i++)
        ha[i]=(ha[i-1]*26+a[i])% base;
    hb[0]=0;
    for (long i=1;i<b.size();i++)
        hb[i]=(hb[i-1]*26+b[i])% base;
    long res=0;
    for (long i=1;i<min(b.size(),a.size());i++)
        if (check(i)) res=i;
    a.erase(0,1);
    b.erase(0,1);
    cout<<a+b.substr(res,b.size()-res);
}
