#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if (i % 2 == 0 || j == (i % 4 == 3 ? 0 : m - 1))
                cout << "#";
            else
                cout << ".";
        cout << '\n';
    }
	return 0;
}
 