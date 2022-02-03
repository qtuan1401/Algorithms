#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > PII;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        int pa = -1, pb = -1;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] != a[i + 1])
                pa = i;
        if (pa == -1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i + 1 < n ;i++)
            if (b[i] != b[i + 1])
                pb = i;
        if (pb == -1) {
            cout << "-1\n";
            continue;
        }
        // cout << pa << " " << pb << " " << a[pa] << " " << a[pa + 1] << endl;
        vector < PII > ans;
        if (a[pb] == a[pb + 1]) {
            if (pa < pb) {
                ans.push_back({pa, pb});
                for (int i = pa; i <= pb; i++)
                    a[i] ^= 1;
            } 
            if (pb < pa) {
                ans.push_back({pb + 1, pa + 1});
                for (int i = pb + 1; i <= pa + 1; i++)
                    a[i] ^= 1;
            }
        }
        cout << a << endl;
        for (int i = 0; i < pb; i++)
            if (a[i] != b[i]) {
                ans.push_back({i, pb + 1});
                for (int j = i; j <= pb + 1; j++)
                    a[j] ^= 1;
            }
        for (int i = n - 1; i >= pb + 2; i--)
            if (a[i] != b[i]) {
                ans.push_back({pb, i});
                for (int j = pb; j <= i; j++)
                    a[j] ^= 1;
            }
        if (a[pb] != b[pb])
            ans.push_back({pb, pb + 1});
        cout << ans.size() << '\n';
        for (PII & res : ans)
            cout << res.first + 1 << " " << res.second + 1 << '\n';
    }
    return 0;
}