#include <bits/stdc++.h>

using namespace std;

const int LIM = 2e5 + 10;

int a[LIM], b[LIM], c[LIM];
int n;

// bool check(int x) {
//     int cnt = 0;
    
//     return (cnt >= x);
// }

// int bs(int l, int r) {
//     int pos = 0;
//     while (l <= r) {
//         int mid = (l + r) >> 1;
//         if (check(mid)) {
//             pos = mid;
//             l = mid + 1;
//         } else
//             r = mid - 1;
//     }
//     return pos;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    // bs(0, n);
    int cnt = 0;
    for (int i = 0, j = 0, k = 0; i < n && j < n && k < n; i++, j++, k++) {
        while (j < n && b[j] <= a[i])
            j++;
        while (k < n && c[k] <= b[j])
            k++;
        if (j < n && k < n) {
            // cout << a[i] << " " << b[j] << " " << c
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}