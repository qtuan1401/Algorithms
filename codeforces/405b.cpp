#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
	bool marked = true, chkL = true;
    int n, cnt = 0, res = 0;

    cin >> n >> s;

	for(int i = 0; i < n; i++) { 
		if (s[i] == '.') {
			cnt++;
			continue;
		}
        chkL = (s[i] == 'L');
        if (s[i] == 'L' && !marked)
            res += (cnt & 1);
        if (s[i] == 'R')
            res += cnt;
        cnt = 0;
        marked = false;
    }

	cout << res + cnt * (chkL == true);
	return 0;
}