#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
set< int > bst;
map<int, int> m;
int type, k, p;

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	while (true) {
		cin >> type;
		if (type == 1) {
			cin >> k >> p;
			m[p] = k;
			bst.insert(p);
		} else if (type == 2) {

			if (!bst.empty()) {
				set< int > :: iterator it = --bst.end();
				cout << m[*it] << "\n";
				bst.erase(it);
			} else
				cout << "0\n";
		} else if (type == 3) {
			if (!bst.empty()) {
				set< int > :: iterator it = bst.begin();
				cout << m[*it] << "\n";
				bst.erase(it);
			} else 
				cout << "0\n";
		} else if (type == 0)
			return 0;
	}
}