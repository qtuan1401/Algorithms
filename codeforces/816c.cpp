#include <bits/stdc++.h>

using namespace std;

const int MXN = 105;

string ans[50005];
int b[MXN][MXN], a[MXN][MXN];
int n, m, x, r;
bool check;

string convert(int n) {
    string s;
    while (n) {
        s = char(n % 10 + 48) + s;
        n /= 10;
    }
    return s;
}

void solveCol() {
	for(int x = 1; x <= 500; x++) {
		for(int j = 0; j < m; j++) {
			int cnt = 0;
			for(int i = 0; i < n; i++) 
				cnt += (a[i][j] + 1 <= b[i][j]);
			if (cnt == n) {
				r++;
				ans[r] = ans[r] + "col " + convert(j + 1);
				for(int i = 0; i < n; i++)
					a[i][j]++;
			}
		}
		check = true;
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++)
				if (a[i][j] != b[i][j]) {
					check = false;
					break;
				}
		if (check)
			break;
	}
}
void solveRow() {
	for(int x = 1; x <= 500; x++) {
		for(int i = 0; i < n; i++) {
			int cnt = 0;
            for(int j = 0; j < m; j++) 
				cnt += (a[i][j] + 1 <= b[i][j]);
			if (cnt == m) {
                r++;
				ans[r] = ans[r] + "row " + convert(i + 1);
                for(int j = 0; j < m; j++)
					a[i][j]++;
			}
		}
		check = true;
		for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
				if (a[i][j] != b[i][j]) {
					check = false;
                    break;
				}
		if (check)
			break;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
    cin >> n >> m;
 	for(int i = 0;  i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> b[i][j];
	if (n < m) {
		solveRow();
		if (!check)
			solveCol();
	}
	else {
		solveCol();
		if (!check)
			solveRow();
	}
	if (!check)
		cout << "-1";
	else {
		cout << r << '\n';
		for(int i = 1; i <= r; i++)
			cout << ans[i] << "\n";
	}
	return 0;
}
