#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, z;
int a[MAXN];

bool check(int x) {
    bool ok = true;
    for(int i = 0; i < x; i++)
        ok &= (a[n - x + i] - a[i] >= z);
    return ok;
}

int bs(int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) 
            l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> z;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	sort(a, a + n);
	cout << bs(0, n / 2 + 1);
}