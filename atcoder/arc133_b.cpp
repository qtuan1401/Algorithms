#include <bits/stdc++.h>

using namespace std;

vector < int > f;
int n;

void update(int i, int val) {
    while (i <= n) {
        f[i] = max(f[i], val);
        i += (i & (-i));
    }
}

int get(int i) {
    int res = 0;
    while (i > 0) {
        res = max(res, f[i]);
        i -= (i & (-i));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector < int > a(n), b(n), pos(n + 1, 0); 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i]] = i + 1;
    }
    
    f.resize(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector < int > num;
        for (int j = a[i]; j <= n; j += a[i])
            num.push_back(pos[j]);
        sort(num.begin(), num.end());
        for (int j = num.size() - 1; j >= 0; j--) {
            int p = num[j];
            int mx = get(p) + 1;
            update(p + 1, mx);
            ans = max(ans, mx);
        }      
    }
    cout << ans;
    return 0;
}