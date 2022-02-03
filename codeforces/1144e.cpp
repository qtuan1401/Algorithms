#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

void convert(string s, int * res) {
	for (int i = 0; i < s.size(); i++) 
		res[i + 1] = s[i] - 'a';
}

string s, t;
int a[MAXN], b[MAXN];
int k;

int main() {
    ios_base::sync_with_stdio(0);
	cin >> k;
    cin >> s >> t;
	convert(s, a);
    convert(t, b);
	for(int i = k; i >= 0; i--) {
		a[i] += b[i];
		if (i) {
			a[i - 1] += a[i] / 26;
			a[i] %= 26;
		}
	}
	
	for (int i = 0; i <= k; i++) {
		int rem = a[i] % 2;
		a[i] /= 2;
		if (i + 1 <= k) {
			a[i + 1] += rem * 26;
		} 
	}
	for (int i = 1; i <= k; i++) 
		cout << char(a[i] + 'a');
	return 0;
}