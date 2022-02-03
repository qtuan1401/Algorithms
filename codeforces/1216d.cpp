#include <bits/stdc++.h>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    int gcd = 0;
    for(int i = 0; i < n; i++)
        gcd = __gcd(gcd, mx - a[i]);
    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += (mx - a[i]) / gcd;
    cout << sum << " " << gcd;
    return 0;
}