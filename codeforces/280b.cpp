#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int a[MXN], l[MXN], r[MXN];
int n;
deque < int > dL, dR;
vector < int > v[2][MXN];

void findMinMax() {
    dL.push_back(0);
    a[0] = a[n + 1] = 2e9;
    for(int i = 1; i <= n; i++) {
        while (dL.size() > 0 && a[dL.back()] <= a[i])
            dL.pop_back();
        l[i] = dL.back() + 1;
        dL.push_back(i);
    }
    dR.push_back(n + 1);
    for(int i = n; i >= 1; i--) {
        while (dR.size() > 0 && a[dR.back()] <= a[i])
            dR.pop_back();
        r[i] = dR.back() - 1;
        dR.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    findMinMax();
    for(int i = 1; i <= n; i++) {
        v[0][l[i]].push_back(a[i]);
        v[1][r[i]].push_back(a[i]);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if (i > 1) {
            for(int j = 0; j < v[1][i - 1].size(); j++)
                res = max(res, a[i] ^ v[1][i - 1][j]);
        }
        if (i < n) {
            for(int j = 0; j < v[0][i + 1].size(); j++)
                res = max(res, a[i] ^ v[0][i + 1][j]);
        }
    }
    cout << res;
    return 0;
}