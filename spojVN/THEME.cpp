#include <bits/stdc++.h>

using namespace std;
int a[1000000],res,n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=5;i<=n-5;i++)
    {
        int Max=1;
        for(int j=n;j>i;j--)
            if (a[j]-a[j-1]==a[j-i]-a[j-i-1])
            {
                Max++;
                if (Max>res) res=Max;
                if (Max==i) break;
            }
            else Max=1;
    }
    if (res<5) cout << 0;
    else cout << res;
    return 0;
}
