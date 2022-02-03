#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 5;

int n, k;
vector < int > p;
int prime[md], cnt[5][md];

void eratos(int n) {
	for(int i = 2; i * i <= n; i++)
		if (prime[i] == 0)
			for(int j = i * i; j <= n; j += i)
				if (prime[j] == 0)
					prime[j] = i;
	for(int i = 2; i <= n; i++)
		if (prime[i] == 0)
			prime[i] = i;
			
}

void factorize(int n, int type) {
	//cout << n << endl;
	while (n != 1) {
		//cout << n << " " << type << " " << prime[n] << " " << cnt[prime[n]] << endl;
		if (type == 0 && cnt[0][prime[n]] == 0) {
			//cout << prime[n] << endl;
			p.push_back(prime[n]);
		}
		int d = 0, pre = prime[n], id = prime[n];
		while (pre == prime[n])
			d++, n /= prime[n];
	//	cout << id  << " " << d << endl;
		if (type == 0)
			cnt[0][id] = d;
		else cnt[1][id] = max(cnt[1][id], d);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	eratos(md - 5);
	factorize(k, 0);
	//cout << prime[k];
	//cout << k << endl;
	//for(int i = 0; i < p.size(); i++)
	//	cout << p[i] << " " << cnt[0][p[i]] << endl;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		factorize(x, 1);
	}
	for(int i = 0; i < p.size(); i++) {
		//cout << cnt[0][p[i]] << " " << cnt[1][p[i]] << endl;
		if (cnt[0][p[i]] > cnt[1][p[i]]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}