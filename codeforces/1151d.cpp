#include <bits/stdc++.h>

using namespace std;

vector < int > a, b, c, id;
int n;

bool cmp(int i, int j) {
    return c[i] > c[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n); b.resize(n); c.resize(n); id.resize(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        id[i] = i;
    }
    long long res = 0;
    sort(id.begin(), id.end(), cmp);
    for (int i = 0; i < n; i++)
        res += 1ll * (a[id[i]] - b[id[i]]) * (i + 1) + 1ll * b[id[i]] * n - a[id[i]];
    cout << res;
    return 0;
}