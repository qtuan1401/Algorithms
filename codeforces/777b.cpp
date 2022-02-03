#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = n - 1;
    for(int i = n - 1; i >= 0; i--)
        if (a[i] <= b[cnt])
            cnt--;
    cout << cnt + 1 << '\n';
    cnt = 0;
    for(int i = 0; i < n; i++)
        if (b[i] > a[cnt])
            cnt++;
    cout << cnt;
    return 0;
}