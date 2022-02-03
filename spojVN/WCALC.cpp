#include <bits/stdc++.h>

using namespace std;
long long int n,d,b,a;
long m;
int main()
{
    cin >> b >> n;
    for(m=1;m<=2*n;m++)
    {
        long long int k=b*n*m*2;
        long long int t=b*m*m;
        long long int s=n*n;
        if ((k-t)%s==0 && (k-t)>0) d++;
    }
    cout << d;
    return 0;
}
