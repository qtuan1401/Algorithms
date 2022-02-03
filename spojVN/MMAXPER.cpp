#include <bits/stdc++.h>

using namespace std;
int a[1000000],b[1000000];
int l1,r1,l2,r2,n;
main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    l1=l2=a[0];
    r1=r2=b[0];
    for(int i=1;i<n;i++)
    {
        if (a[i]>b[i]) swap(a[i],b[i]);
        l1=max(l1+abs(b[i]-b[i-1]),r1+abs(b[i]-a[i-1]))+a[i];
        r1=max(l2+abs(a[i]-b[i-1]),r2+abs(a[i]-a[i-1]))+b[i];
        l2=l1;
        r2=r1;
    }
    cout << max(l1,r1);
}
