#include <bits/stdc++.h>

using namespace std;

int q, n;

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> q;
	while (q--) {
		priority_queue< int, vector< int >, greater< int > > heap;
		cin >> n;
		for(int i=1;i<=n;i++) {
			int x;
			cin >> x;
			heap.push(x);
		}

		long long res = 0;

		for(int i=1;i<n;i++)  {
			int val1 = heap.top();
			heap.pop();
			res += val1;
			int val2 = heap.top();
			heap.pop();
			res += val2;
			heap.push(val1 + val2);
		}

		cout << res << "\n";
	}
	return 0;
}