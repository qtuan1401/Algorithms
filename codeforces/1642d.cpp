#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map < int, int > cnt;
        vector < int > b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
            cnt[x]++;
        }

        bool isFalse = false;
        for (int i = 0; i < n; i++)
            if (cnt[b[i]] & 1) isFalse = true;

        if (isFalse) {
            cout << "-1\n";
            continue;
        } 

        bool ok = false;
        
        int l = 0;
        vector < PII > pairs;
        vector < int > ans;
        // pairs.push_back({n, b[n - 1]});
        // b.push_back(b[n - 1]);
        // b.push_back(b[n - 1]);
        while (!ok) {
            int r = 0;
            int m = b.size();
            // for (int i = 0; i < m; i++) cout << b[i] << " ";
            // cout << '\n';
            for (int i = 1; i < m; i++)
                if (b[i] == b[0]) {
                    r = i;
                    break;
                }
            for (int i = 1; i < r; i++)
                pairs.push_back({l + r + i, b[i]});
            
            // cout << l << " * " << r << endl;
            ans.push_back(r * 2);
            l += r * 2;
            vector < int > temp;
            for (int i = r - 1; i >= 1; i--)
                temp.push_back(b[i]);
            for (int i = r + 1; i < m; i++)
                temp.push_back(b[i]);
            
            b.clear();
            for (int &val : temp) b.push_back(val);
            ok = !b.size();
        }
        cout << pairs.size() << '\n';
        for (PII &e : pairs) cout << e.first << " " << e.second << '\n';
        cout << ans.size() << '\n';
        for (int &val : ans) cout << val << " ";
        cout << '\n';
    }
    return 0;
}