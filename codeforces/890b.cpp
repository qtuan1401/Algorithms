#include <bits/stdc++.h>

using namespace std;

bool marked[200005], vis[200005];

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    int tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tot += (marked[a[i]] == false);
        marked[a[i]] = true;
    }

    int cnt = 0;

    for(int i = n - 1; i >= 0; i--)
        if (vis[a[i]] == false) {
            cnt++;
            if (cnt == tot) {
                cout << a[i];
                return 0;
            }
            vis[a[i]] = true;
        }
    return 0;
}