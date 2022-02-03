#include <bits/stdc++.h>

using namespace std;

const int md = 1010;

int x[md], y[md], ans[md];
int n, l = 1;
bool had[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
        if (y[i] != n) {
            cout << "NO";
            return 0;
        }   
    }
    sort(x + 1, x + n);
    for(int i = 1; i < n; i++)
        if (x[i] < i) {
            cout <<  "NO";
            return 0;
        }
    for(int i = 1; i < n; i++) {
        if (!had[x[i]]) {
            ans[i] = x[i];
            had[x[i]] = true;
        } else {
            while (had[l]) 
                l++;
            ans[i] = l;
            had[l] = true;
        }
    }
    ans[n] = n;
    cout << "YES\n";
    for(int i = 1; i < n; i++)
        cout << ans[i] << " " << ans[i + 1] << '\n';
    return 0;
}