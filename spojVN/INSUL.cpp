#include <bits/stdc++.h>

using namespace std;
long long int res=0, n,i,res1=0,res2=0,a[1000000];
int main()
{
    cin >> n;
    for(i=1;i<=n;i++)
    {
    	cin >> a[i];
    	res+=a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n/2;i++)
    {
        res1+=a[i];
        res2+=a[n-i+1];
    }
    cout << res+res2-res1;
    return 0;
}
