#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-9;

int n;
vector < int > a;

bool checkAvg(long double x) {
    vector < long double > b(n);
    for (int i = 0; i < n; i++)
        b[i] = (long double)a[i] - x;
    long double f = 0, g = 0;
    for (int i = 0; i < n; i++) {
        // cout << f << " " << g << " " << max(f, g) << " " << b[i] << endl;
       
        long double mx = max(f, g) + b[i];
        g = f;
        f = mx; 
        // cout << f << " " << g << " " << mx << endl;
    }
    return max(f, g) >= 0;
}

long double bsAvg(long double l, long double r) {
    while (r - l > EPS) {
        long double mid = (l + r) / 2;
        if (checkAvg(mid)) {
            l = mid;
        } else r = mid;
    }
    return l;
}

bool checkMedian(int x) {
    vector < int > b(n);
    for (int i = 0; i < n; i++)
        b[i] = (a[i] >= x) * 2 - 1;
    int f = 0, g = 0;
    for (int i = i; i < n; i++) {
        int mx = max(f, g) + b[i];
        g = f;
        f = mx;
    }
    return max(f, g) > 0;
}

int bsMedian(int l, int r) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (checkMedian(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fixed << setprecision(6) << bsAvg(1, 1e9) << '\n';
    cout << bsMedian(1, 1e9) << '\n';
    return 0;
}