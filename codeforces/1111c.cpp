#include <bits/stdc++.h>

using namespace std;

vector < long long > a;
long long n, k, A, B;

long long calc(long long l, long long r) {
	long long i = lower_bound(a.begin(), a.end(), l) - a.begin();
	long long j = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
	long long tot = j - i + 1;
	long long res = A;
	if (tot > 0) 
	    res = B * tot * (r - l + 1);
	if(l == r || tot == 0)
		return res;
	long long mid = (l + r) / 2;
	res = min(res, calc(l, mid) + calc(mid + 1, r));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
    cin>>n >> k >> A >> B;
    a.resize(k);
	for(int i = 0; i < k; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	
    cout << calc(1, (1ll << n));
	return 0;
}