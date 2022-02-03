#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, d;
long long h[MXN];
int fw[MXN], par[MXN], trc[2][MXN];

void update(int x, int val, int type) {
	while (x < MXN) {
		if(fw[val] > fw[trc[type][x]])
			trc[type][x] = val;
		x += (x & (-x));
	}
}

int get(int x, int type) {
	int res = 0;
	while (x > 0) {
		if (fw[res] < fw[trc[type][x]])
			res = trc[type][x];
		x -= (x & (-x));
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> d;
    vector < long long > nH;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        nH.push_back(h[i]);
    }
    
    sort(nH.begin(), nH.end());
    int pos = 0;
	for(int i = 1; i <= n; i++) {
		int p = lower_bound(nH.begin(), nH.end(), h[i]) - nH.begin() + 1;
        int p1 = upper_bound(nH.begin(), nH.end(), h[i] - d) - 1 - nH.begin() + 1;
        int p2 = lower_bound(nH.begin(), nH.end(), h[i] + d) - nH.begin() + 1;
        //cout << p << " " << p1 << " " << p2 << endl;
        int res1 = get(p1, 0), res2 = get(n - p2 + 1, 1);
		if(!fw[res1] && !fw[res2]) {
            fw[i] = 1;
            par[i] = 0;
        } else if (fw[res1] > fw[res2]) {
			fw[i] = fw[res1] + 1;
            par[i] = res1;
        } else {
			fw[i] = fw[res2] + 1;
            par[i] = res2;
        }
		update(p, i, 0);
		update(n - p + 1, i, 1);
		if (fw[i] > fw[pos])
            pos = i;
	}

    vector < int > ans;
    for(int i = pos; i > 0; i = par[i])
        ans.push_back(i);
    cout << fw[pos] << '\n';
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
	return 0;
}