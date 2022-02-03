#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

vector < int > v[md], sum;
int a[md * 2];
int n, m, k, res = 0;

int bs(int l, int r) {
    int pos = r + 1;
    int p = pos;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << p <<" " << mid << " " << sum[p] - sum[mid - 1] << endl;
        if (sum[p] - sum[mid] <= k) {
            pos = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return pos;
}

int solve(vector < int > color) {
    if (color.empty())
        return 0;
    if (color.size() == 1)
        return 1;
    sum.clear();
    sum.push_back(0);
    for(int i = 1; i < color.size(); i++)
        sum.push_back(color[i] - color[i - 1] - 1);
    for(int i = 1; i < sum.size(); i++)
        sum[i] += sum[i - 1];
    //cout << sum.size() << " " << color.size() << endl;
    //cout << endl;
    int res = 0;
    for(int i = 1; i < sum.size(); i++) {
        int pos = bs(0, i - 1);
        //cout << color[i] <<": " << color[pos] << " " << sum[i] <<" " << sum[pos] << "| ";
        res = max(res, color[i] - color[pos] + 1 - sum[i] + sum[pos]);
        //cout << res << endl;
    }
    //cout << endl;
    return res;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for(int i = 1; i <= m; i++) 
        res = max(res, solve(v[i]));
    cout << res;
    return 0;
}