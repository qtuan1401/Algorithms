#include "bits/stdc++.h"

using namespace std;

typedef pair < long long, long long > II;
typedef pair < II, long long > III;

const int MXN = 4e5 + 10;
const long long INF = 2e18;

int n, m;
long long l[MXN], r[MXN], ans[MXN];
III a[MXN];
priority_queue < III, vector < III >, greater < III > > heap;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    if (m < n - 1) {
        cout << "No";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i].first.first;
        a[i].first.second = INF;
        a[i].second = i;
    }
    for(int i = 0; i < n - 1; i++) {
        a[i + m].first.first = l[i + 1] - r[i];
        a[i + m].first.second = r[i + 1] - l[i];
        a[i + m].second = i;
    }
    m += n - 1;
    sort(a, a + m);
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        //cout << "(" << a[i].first.first << " " << ((a[i].first.second == INF) ? -1 : a[i].first.second) << " " << a[i].second << ") ";
        if (a[i].first.second == INF) {
            if (heap.size()) {
                III cur = heap.top(); heap.pop();
                if (cur.first.second <= a[i].first.first && a[i].first.first <= cur.first.first)
                    ans[cur.second] = a[i].second, cnt++;
                else {
                    cout << "No";
                    return 0;
                }
            }
        } else {
            heap.push(III(II(a[i].first.second, a[i].first.first), a[i].second));
        }
    }
    //cout << cnt << endl;
    if (cnt != n - 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 0; i < n - 1; i++)
        cout << ans[i] + 1 << " ";
}