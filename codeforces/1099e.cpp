#include<bits/stdc++.h>

const int MXN = 3e5 + 10;

using namespace std;

string cs = "ACGT";

int n, m, ans = 1e9;
string c[MXN], res[MXN];
bool marked[MXN];

inline int findChar(int i, int j) {
    return (i % 2) * 2 + (j % 2);
}

void calcRow() {
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int diff1 = 0, diff2 = 0;
        for(int j = 0; j < m; j++) {
            int pos = findChar(i, j);
            diff1 += cs[pos] != c[i][j];
            diff2 += cs[pos ^ 1] != c[i][j];
        }
        marked[i] = diff1 < diff2;
        cur += min(diff1, diff2);
    }
    if (cur < ans){
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++) {
                int pos = findChar(i, j);
                res[i][j] = (marked[i] ? cs[pos] : cs[pos ^ 1]);
            }
        }
        ans = cur;
    }
}

void calcCol() {
    int cur = 0;
    for(int i = 0; i < m; i++) {
        int diff1 = 0, diff2 =0;
        for(int j = 0; j < n; j++) {
            int pos = findChar(i, j);
            diff1 += cs[pos] != c[j][i];
            diff2 += cs[pos ^ 1] != c[j][i];
        }
        marked[i] = diff1 < diff2;
        cur += min(diff1, diff2);
    }
    if (cur < ans){
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int pos = findChar(i, j);
                res[j][i] = (marked[i] ? cs[pos] : cs[pos ^ 1]);
            }
        }
        ans = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		res[i] = c[i];
	}

	do {
        calcRow();
        calcCol();
	} while(next_permutation(cs.begin(), cs.end()));
	
	for(int i = 0;i < n; i++) 
        cout << res[i] << '\n';
}