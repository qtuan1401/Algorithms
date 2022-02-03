#include <bits/stdc++.h>

using namespace std;

int n, sum, sum1;
int a[3005];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    n *= 2;
    for(int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n / 2; i++)
        sum1 += a[i];
    if (sum1 * 2 == sum)
        cout << "-1";
    else {
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }
    return 0;
}