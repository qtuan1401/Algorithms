#include <bits/stdc++.h>
using namespace std;
#define md int(1e3 + 5)
#define REP(i, n) for(int i = 1; i <= n; i++)
#define DOW(i, b, a) for(int i = (b); i >= (a); i--)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
string res[md][md];	
int n, m, a[md], s;
inline string add(string a, string b) {
	string res = "";
	int carry = 0;
	while (a.size() < b.size())
		a = "0" + a;
	while (b.size() < a.size())
		b = "0" + b;
	int n = a.size();
	DOW(i, n - 1, 0) {
		int s = (a[i] - '0') + (b[i] - '0') + carry;
		carry = s / 10;
		s %= 10;
		res = char(s + 48) + res;
	}
	if (carry) 
		res = "1" + res;
	return res;
}
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &m); 
	REP(i, m)
		scanf("%d", &a[i]), s += a[i];
	int k = n - s + 1;
//	cout << k << " " << m <<endl;
	if (n < s + m - 1) {
		printf("0");
		return 0;
	}
	FOR(i, 0, k)
		FOR(j, 0, i)
			res[i][j] = "0";	
	FOR(i, 0, k)
		FOR(j, 0, i)
			if (i == j || j == 0)
				res[i][j] = "1";
			else
				res[i][j] = add(res[i - 1][j - 1], res[i - 1][j]);
	cout << res[k][m];
	return 0;
}