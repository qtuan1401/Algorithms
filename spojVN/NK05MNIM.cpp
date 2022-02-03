#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int n, x, nim=0, cnt=0;
        cin >> n;
        for (int i=1; i<=n; i++)
        {
            cin >> x;
            if (x == 1) cnt++;
            nim ^= x;
        }
        if (cnt == n)
        {
            if (n%2 == 0)
                cout << 1 << endl;
            else
                cout << -1 << endl;
        }
       else
        {
            if (nim > 0)
                cout << 1 << endl;
            else
                cout << -1 << endl;
       }
    }
    return 0;
}

