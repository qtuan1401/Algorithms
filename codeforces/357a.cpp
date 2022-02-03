#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int m;
	cin >> m;
    vector < int > sum(m + 1);
    int tot = 0;
	for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        tot += x;
        sum[i] = sum[i - 1] + x;
    }
    int x, y;
	cin >> x >> y;
    for(int i = 1; i <= m; i++)
        if (x <= sum[i] && sum[i] <= y && x <= tot - sum[i] && tot - sum[i] <= y) {
            cout << i + 1;
            return 0;
        }
    cout << 0;
	return 0;
}
