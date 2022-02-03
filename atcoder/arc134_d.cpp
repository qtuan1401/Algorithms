#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;
typedef pair < PII, int > PIII;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(2 * n);
    vector < PIII > b(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        b[i] = {{a[i], i}, a[i + n]};
    }
    sort(b.begin(), b.end());
    int mn = 1e9 + 1;
    for (int i = 0; i < n; i++)
        if (b[i].first.first == b[0].first.first)
            mn = min(mn, b[i].second);
    if (mn <= b[0].first.first) {
        cout << b[0].first.first << " " << mn << '\n';
        return 0; 
    }
    vector < int > pos;
    pos.push_back(b[0].first.second);
    pos.push_back(b[0].first.second + n);
    int cur = 0, fst = b[0].second, inc = -1;
    for (int i = 1; i < n; i++) {
        if (b[i].first.first < fst && b[i].first.second >= cur) {
            pos.push_back(b[i].first.second);
            pos.push_back(b[i].first.second + n);
            if (inc == -1) {
                if (b[i].second > fst) inc = 1;
                if (b[i].second < fst) inc = 0;
            }
            cur = b[i].first.second;
        } else if (b[i].first.first == fst && inc == 1 && b[i].first.second >= cur) {
            pos.push_back(b[i].first.second);
            pos.push_back(b[i].first.second + n);
            cur = b[i].first.second;
        }
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < pos.size(); i++)
        cout << a[pos[i]] << " ";
    return 0;
}