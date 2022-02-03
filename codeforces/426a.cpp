#include <bits/stdc++.h>

using namespace std;

int n, s, mx, sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    if (sum - mx <= s)
        cout << "YES";
    else
        cout << "NO";
	return 0;
}