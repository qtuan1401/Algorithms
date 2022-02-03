#include<bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
	a[n] = 2e9;
    int l = 0, r = 0, pos = -1;
    bool marked = false;
	for(int i = 1; i <= n; i++)
		if (a[i] < a[i - 1]) {
			if (marked) {
                cout << "no";
                return 0;
            }
            if (pos == -1)
                pos = i - 1;
		} else if (pos != -1) {
			if (a[i] <= a[pos] || (a[i - 1] <= a[pos - 1] && pos > 0)) {
                cout << "no";
                return 0;
            } else {
                l = pos; 
                r = i - 1;
                marked = 1;
                pos = -1;
            }
		}
	cout << "yes\n";
    cout << l + 1 << " " << r + 1; 
	return 0;
}