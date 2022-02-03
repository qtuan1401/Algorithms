#include <iostream>

using namespace std;
int n,k;
int d=1;
void xuli(int x)
{
    if ((x-k>0) && ((x-k)%2==0))
    {
        d++;
        xuli((x-k)/2);
        xuli((x+k)/2);
    }
}
int main()
{
    cin >> n >> k;
    xuli(n);
    cout << d;
    return 0;
}