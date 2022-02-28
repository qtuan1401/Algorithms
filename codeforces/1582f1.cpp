#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector < int > res;
    vector < vector < int > > val(501);
    for (int i = 0; i <= 500; i++)
        val[i].push_back(0);
    set < int > s;
    s.insert(0);
    res.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) continue;
        s.insert(x);
        auto it = s.find(x);
        int y = *(--it);
        // cout << x << " " << y << endl;
        for (int v : val[y]) {
            // cout << v <<  " * " << x << endl;
            val[x].push_back(v ^ x);
            res.push_back(v ^ x);
        }
        sort(val[x].begin(), val[x].end());
        val[x].erase(unique(val[x].begin(), val[x].end()), val[x].end());
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}