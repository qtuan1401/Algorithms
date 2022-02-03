#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 10;

int n, k;
long long a[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    long long ans = (sum % n != 0);
    long long mx = a[n - 1], mn = a[0];
    int temp = k;
    //cout << mx << " " << mn << endl;
    for(int i = 1; i < n; i++)
        if (temp >= (a[i] - a[i - 1]) * i) {
            temp -= (a[i] - a[i - 1]) * i;
            mn = a[i];
        } else {
            mn = temp / i + a[i - 1];
            break;
        }
    temp = k;
    for(int i = n - 2; i >= 0; i--) {
        if (temp >= (a[i + 1] - a[i]) * (n - i - 1)) {
            temp -= (a[i + 1] - a[i]) * (n - i - 1);
            mx = a[i];
        } else {
            mx = a[i + 1] - (temp / (n - i - 1)); 
            break;
        }
    }
    cout << mx << " " << mn << endl;
    cout << max(ans, mx - mn);
    return 0;
}