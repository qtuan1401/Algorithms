#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 10;
int pos[MXN], f[MXN];

int main() {
	ios_base::sync_with_stdio(false);
	string s;
    cin >> s;
    int r = 0, res = 0, cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') 
            pos[++r] = i;
		else if (r > 0) {
			f[i] = i - pos[r] + 1 + f[pos[r] - 1];
			r--;
		    cnt += (f[i] == res);
            if (res < f[i]) {
                res = f[i];
                cnt = 1;
            }
		}
	}
    cout << res << " " << cnt;
	return 0;
}
