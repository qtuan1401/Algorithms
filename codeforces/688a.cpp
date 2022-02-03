#include<bits/stdc++.h>

using namespace std;

int d, n;

int main() {
    ios_base::sync_with_stdio(0);
	cin >> d >> n;
    int cnt = 0, res = 0;
	for(int i = 0; i < n; i++) {
		bool check = 1;
		for (int j = 0; j < d; j++) {
            char c;
            cin >> c;
            check &= (c == '1');
        }
        if (check)
            cnt = 0;
        else
            cnt++;
        res = max(res, cnt);
	}
    cout << res;
    return 0;
}
