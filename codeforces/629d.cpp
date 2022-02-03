#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;
const double PI = 3.14159265359;

long long fw[MXN], c[MXN], s[MXN];
pair < long long, int > a[MXN];
int n, cnt;

void update(int x, long long val) {
    while (x < MXN) {
        fw[x] = max(fw[x], val);
        x += (x & (-x));
    }
}

long long get(int x) {
    long long res = 0;
    while (x > 0) {
        res = max(res, fw[x]);
        x -= (x & (-x));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long r, h;
        cin >> r >> h;
        a[i].first = s[i] = r * r * h;
        a[i].second = i;
    }

    sort(a, a + n);
    c[a[0].second] = ++cnt;
    for(int i = 1; i < n; i++)
        c[a[i].second] = cnt += (a[i - 1].first != a[i].first);
    
    long long res = 0;
    for(int i = 0; i < n; i++) {
        long long mx = get(c[i] - 1);
        res = max(res, mx + s[i]);
        //cout << i << " " << mx  << " " << c[i] << " " << mx + s[i] << endl;
        update(c[i], mx + s[i]);
    }

    cout << fixed << setprecision(8);
    cout << (double)res * PI;
    return 0;
}