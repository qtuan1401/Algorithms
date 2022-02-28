#include <bits/stdc++.h>

using namespace std;

const int LIM = 5e5;

vector < int > fw;

int get(int x) {
    int res = 0;
    while (x > 0) {
        res += fw[x];
        x -= (x & (-x));
    }
    return res;
}

void update(int x, int n) {
    while (x <= n) {
        fw[x]++;
        x += (x & (-x));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > cnt(n + 1, 0);
        fw.clear();
        fw.resize(n + 1, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if (i > 0) sum += i - get(x);
            update(x, n);
        }
        for (int i = 1; i <= n; i++)
            if (cnt[i] > 1) sum = 0;
        if (sum & 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}