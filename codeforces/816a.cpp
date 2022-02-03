#include <bits/stdc++.h>

using namespace std;

string s;

inline bool check(int h, int m) {
	char s[4];
	s[0] = int(h / 10) + '0';
	s[1] = int(h % 10) + '0';
	s[2] = int(m / 10) + '0';
	s[3] = int(m % 10) + '0';
	if (s[3] == s[0] && s[1] == s[2])
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin >> s;
	int h = (s[0] - '0') * 10  + (s[1] - '0');
	int m = (s[3] - '0') * 10  + (s[4] - '0');
	if (check(h, m)) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i < 1440; i++) {
		m++;
		if (m == 60) {
			m = 0;
			h++;
			if (h > 23) 
				h = 0;
		}
		if (check(h, m)) {
			cout << i + 1;
			return 0;
		}
	}
    return 0;
}