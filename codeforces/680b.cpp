#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, a;
    cin >> n >> a;
    int res = 0;
    vector < int > t(n);
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        res += t[i];
    }
    for(int i = 0; a + i <= n && a - i > 0; i++)
        if (t[a + i] != t[a - i])
            res--;
    cout << res;
    return 0;
}