#include <iostream>

using namespace std;

int main()
{
    int a[200000],m,n,i,j;
    cin >> m >> n;
    for (i=2;i<=n;i++) a[i]=1;
    for (i=2;i<=n/2;i++)
        if (a[i]==1)
        {
            for (j=2;j<=n/i;j++) a[i*j]=0;
        }
    a[1]=0;
    for (i=m;i<=n;i++)
        if (a[i]==1)
        {
            cout << i << endl;
        }
    return 0;
}