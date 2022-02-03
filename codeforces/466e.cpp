#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;
int p[MXN], root[MXN];
vector < int > ver, par;
int n, m;

int findRoot(int x) {
    if (root[x] == 0)
        return x;
    return root[x] = findRoot(root[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    while (m--) {
		int type;
		cin >> type;
		if(type == 1) {
			int x, y;
			cin >> x >> y ;
			p[x] = y ;
			root[x] = y;
		}
		else if (type == 2) {
			int x;
			cin >> x;
			ver.push_back(x);
			par.push_back(findRoot(x));
		}
		else {
			int x, i;
			cin >> x >> i;
			int y = ver[i - 1], z = par[i - 1];
			for ( ; y != z; y = p[y])
				if (y == x)
                    break;
			if(x == y)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
