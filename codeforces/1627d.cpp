#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < bool > marked(MXN, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        marked[x] = 1;
    }
    int cnt = 0;
    for (int i = MXN - 1; i >= 1; i--) {
        if (marked[i] == 0) {
            int num = 0;
            for (int j = i * 2; j < MXN; j += i)
                if (marked[j]) {
                    if (num == 0) {
                        num = j;
                    } else if (num != 0 && j % num != 0) {
                        marked[i] = 1;
                        cnt++;
                        break;
                    }
                }
        }
    }
    cout << cnt << '\n';
    return 0;
}