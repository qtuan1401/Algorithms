#include <bits/stdc++.h>

using namespace std;

map < string, int > f1, f2;
int n;

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;

    vector < string > ans;
	for(int i = 0; i < n; i++) {
        string teamName, homeName;
		cin >> teamName >> homeName;
		string sf = teamName.substr(0, 3), so = teamName.substr(0, 2) + homeName[0];
		if (f1.count(so)) {
			if (f1.count(sf) || f2.count(sf)) {
				cout << "NO\n";
				return 0;
			}
			f1[sf] = 1;
			ans.push_back(sf);
		} else {
			f1[so] = 1;
			ans.push_back(so);
		}
		f2[sf] = 1;
	}

	cout << "YES\n";
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}