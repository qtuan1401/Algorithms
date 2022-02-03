#include <bits/stdc++.h>

const int MXN = 7e3 + 10;

using namespace std; 

int marked[MXN][2], s[2][MXN], len[2], remain[7005][2]; 
int n;

void solve(int pos, int cur) {
	int nxt = cur ^ 1; 
	for (int u = 0; u < len[nxt]; u++) {
		int v = (pos - s[nxt][u] + n) % n; 
		if (marked[v][nxt])
			continue; 
		if (marked[pos][cur] == 1) {
            remain[v][nxt]--;
			if (!remain[v][nxt]) {
				marked[v][nxt] = 2; 
				solve(v, nxt); 
			}
		} else {
			marked[v][nxt] = 1; 
			solve(v, nxt); 
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int j = 0; j < 2; j++) {
        cin >> len[j];
        for (int i = 0; i < len[j]; i++)
            cin >> s[j][i];
    }
    marked[0][0] = marked[0][1] = 2;
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) 
            remain[i][j] = len[j];
    }
    solve(0, 0);
    solve(0, 1);
    for(int j = 0; j < 2; j++) {
        for(int i = 1; i < n; i++) {
            if (marked[i][j] == 1)
                cout << "Win ";
            else if (marked[i][j] > 0)
                cout << "Lose ";
            else 
                cout << "Loop ";
        }
        cout << '\n';
    }
	return 0; 
}
