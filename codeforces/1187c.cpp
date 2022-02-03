#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int md = 1e4 + 10;

int n, m;

vector < II > seg[5];
vector < II > s1;
int a[md], dd[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        seg[type].push_back(II(l, r));
    }
    for(int i = 0; i <= 1; i++)
        sort(seg[i].begin(), seg[i].end());
    if (seg[1].size()) {
        int l = seg[1][0].first, r = seg[1][0].second;
        //cout << l << " " << r << endl;
        s1.push_back(seg[1][0]);
        for(int i = 1; i < seg[1].size(); i++) {
            if (seg[1][i].first <= r) {
                r = max(r, seg[1][i].second);
                s1.pop_back();
             //   cout << l << " * " << r << endl;
                s1.push_back(II(l, r));
            } else {
                l = seg[1][i].first; r = seg[1][i].second;
                s1.push_back(seg[1][i]);
            }
        }
    }
    //if (n == 1000 && n == m) {
    //}
    for(int i = 0; i < s1.size(); i++) {
    //    cout << s1[i].first << " " << s1[i].second << endl;
        for(int j = s1[i].first; j <= s1[i].second; j++)
            dd[j] = i + 1;
    }
    int diff = 0;
    for(int i = 1; i <= n; i++) {
        diff += ((dd[i] != dd[i - 1]) || (dd[i] == 0));
        a[i] = n + 1 - diff;
    }
    for(int i = 0; i < seg[0].size(); i++) {
        int u = seg[0][i].first, v = seg[0][i].second;
        if (a[u] == a[v] && dd[u] == dd[v] && dd[u] > 0) {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            if (i == 1) 
                a[i] = 1e9;
            else a[i] = min(a[i - 1], 10000) - 1;
        }
    }
    //cout << seg[0][0].first << " " << seg[0][0].second << endl;
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}