#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < int > fw;

long long get(int x) {
    long long ans = 0;
    while (x > 0) {
        ans += fw[x];
        x -= (x & (-x));
    }
    return ans;
}

void update(int x) {
    while (x <= n) {     
        fw[x]++;
        x += (x & (-x));   
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n >> m;
        vector < pair < int, int > > a;
        fw.resize(n + 10);
        for (int i = 0; i < fw.size(); i++) fw[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                a.push_back({x, i + 1});
            }
        }

        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n * m; i++) {
            ans += get(a[i].second + 1);
            cout << a[i].second << " " << get(a[i].second + 1) << endl;
            for (int i = 1; i <= n; i++) cout << fw[i] << " ";
            cout
            update(a[i].second);
        }

        cout << ans << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += 1ll * j * (n - 1 - i);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}