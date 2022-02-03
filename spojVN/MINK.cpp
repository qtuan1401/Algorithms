#include <bits/stdc++.h>

using namespace std;

deque< int > dmin;
int a[1000005];
int n, k, t;

void push(int i) {
	while (!dmin.empty() && a[dmin.back()] > a[i])
		dmin.pop_back();
	dmin.push_back(i);
}

void pop(int i) {
	while (!dmin.empty() && dmin.front() <= i)
		dmin.pop_front();
}

int main() {
	//freopen("test.inp", "r", stdin);	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		dmin.clear();
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=k;i++)
			push(i);
		cout << a[dmin.front()] << " ";
		for(int i=k+1;i<=n;i++) {
			pop(i - k);
			push(i);
			cout << a[dmin.front()] <<" ";
		}
		cout << '\n';
	}
	return 0;
}