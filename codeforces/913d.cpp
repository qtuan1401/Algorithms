#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;
int a[MXN], b[MXN];
int n;
int lim;
vector < int > res;

bool check(int x) {
    vector < pair < int, int > > tasks;
    for(int i = 0; i < n; i++)
        if (a[i] >= x)
            tasks.push_back(make_pair(b[i], i));
    sort(tasks.begin(), tasks.end());
    if (tasks.size() < x)
        return false;
    //cout << x << endl;
    //for(int i = 0; i < tasks.size(); i++)
    //    cout << "(" << tasks[i].first << " " << tasks[i].second << ") ";
    //cout << endl;
    int sum = 0;
    for(int i = 0; i < x; i++)
        sum += tasks[i].first;
    //cout << sum << endl;
    if (sum <= lim) {
        res.clear();
        for(int i = 0; i < x; i++)
            res.push_back(tasks[i].second + 1);
    } else return false;
    return true;
}

void bs(int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> lim;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    bs(0, n);
    cout << res.size() << '\n' << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}