#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector < int > a(n);
    for(int i = 0; i < n; i++) {
        if (k > 0)
            a[i] = m;
        else
            a[i] = 1;
        k = a[i] - k;
    }
	a[n - 1] -= k;
	if (a[n - 1] <= 0 || a[n - 1] > m) {
        cout << "-1";
        return 0;
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}