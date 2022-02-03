#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
long d,m,n,i,k,j;
string a[100001];

int main()
{
    cin >> m ;
    for (i=1;i<=m;i++)
    {
        cin >> k;
        for (j=1;j<=k;j++)
        {
            n++;
            cin >> a[n];
        }
    }
    sort(a+1,a+n+1);
    d=1;
    for (i=1;i<=n-1;i++)
    if (a[i]!=a[i+1]) d++;
    cout << d;
    return 0;
}
