#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MXN = 1e5 + 10;

II a[MXN];
int n, res = 1e9, sum;
multiset < int > ms;

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
        cin >> a[i].first;
	for(int i = 0; i < n; i++) {
        cin >> a[i].second;
        sum += a[i].second;
    }
	sort(a, a + n);

	for(int i = 0; i < n; i++) {
		int j = i + 1;
        int tot = a[i].second;
		while (j < n && a[j].first == a[j - 1].first) {
            tot += a[j].second;
			j++;
        }
        //cout << i << " " << j << " " << tot << endl;
		int ans = sum - tot, cnt = j - i - 1;
		for(multiset <int> :: iterator it = ms.begin(); it != ms.end() && cnt; it++) {
			cnt--;
			ans += *it;
		}
        res = min(res, ans);
		while (i != j)
			ms.insert(-a[i++].second);
		i--;
	}

	cout << res;
    return 0;
}
