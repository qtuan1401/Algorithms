#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int n, k;
int a[MAXN], f[MAXN];

int bsL(int l, int r, int val) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= val) {
            pos = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return pos;
}

bool check(int x) {
    //cout << x << endl;
    f[1] = 1;
    for(int i = 1, l = 1; i <= n; i++) {
        while (a[i] - a[l] > x)
            l++;
    //    cout << i << " " << l << endl;
        f[i + 1] = (i >= k && f[i - k + 1] - f[l - 1] > 0);
        f[i + 1] += f[i];
    }
    //for(int i = 1; i <= n; i++)
    //    cout << "(" << f[i] << " " << a[i] << ") ";
    //cout << endl;
    //cout << x << endl;
    return f[n + 1] - f[n] > 0;
}

int bs(int l, int r) {
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            pos = mid; 
            r = mid - 1;
        } else l = mid + 1;
    }
    return pos;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << bs(0, 1e9);
    return 0;
}