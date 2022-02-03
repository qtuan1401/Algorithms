#include <iostream>

using namespace std;

int main()
{
    int r,j,a,d,n,m,k,i;
    cin >> n >> m;d=0;
    for (i=n;i<=m;i++)
    {
        k=i;
        a=i;
        while (a!=0)
        {
            j=j*10+a%10;
            a=a/10;
        }
        while (j!=0)
        {
            r=k%j;
            k=j;
            j=r;
        }
        if (k==1)
        {
            d++;
        }
    }
    cout << d;
    return 0;
}
