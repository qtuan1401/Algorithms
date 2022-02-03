#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
    vector < int > a(n);
	for(int i = 0; i < n; i++) 
        cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) 
				if (a[i] + a[j] == a[k] && i != j && i != k && j != k) {
                    cout << k + 1 << " " << j + 1 << " " << i + 1 << '\n';
                    return 0;
                }
    cout << "-1";
    return 0;
}