#include <bits/stdc++.h>
using namespace std;
int l, k, m;
bool win[int(1e6) + 5];
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d %d %d", &l, &k, &m);
	win[0] = false;
	for(int i=1;i<=int(1e6);i++) 
		win[i] = (win[i - 1] == false || (i - k >= 0 && win[i - k] == false) || (i - l >= 0 && win[i - l] == false));
	while (m--) {
		int x;
		scanf("%d", &x);
		cout << ((win[x] == true) ? "A" : "B");
	}
	cout << endl;
}