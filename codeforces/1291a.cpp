#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n >> s;
		vector < char > c;
		for(int i = 0; i < s.size(); i++)
			if ((s[i] - '0') % 2)
				c.push_back(s[i]);
		if (c.size() < 2)
			cout << "-1\n";
		else
			cout << c[0] << c[1] << '\n';
	}
}