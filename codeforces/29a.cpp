#include <bits/stdc++.h>

using namespace std;

const int MXN = 105;

int pos[40005], x[MXN], d[MXN];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    memset(pos, -1, sizeof(pos));
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> d[i];
        pos[x[i] + 20000] = i;
    }

    for(int i = 0; i < n; i++) {
        int p = pos[x[i] + d[i] + 20000];
        if (p == -1)
            continue;
        if (pos[x[p] + d[p] + 20000] == i) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}