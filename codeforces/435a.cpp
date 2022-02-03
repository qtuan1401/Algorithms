#include<bits/stdc++.h>

using namespace std;

int n, m, cnt = 1, sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        if (sum > m) {
            cnt++;
            sum = x;
        }
    }
    cout << cnt;
	return 0;
}