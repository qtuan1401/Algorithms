#include <bits/stdc++.h>

using namespace std;

const int MXN = 55;

long long a[MXN], b[MXN], res[MXN];

int main() {
    int n;
    ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int j = 1; j <= 5; j++)
		cin >> b[j];
	long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        for(int j = 5; j >= 1; j--) {
            res[j] += sum / b[j];
            sum %= b[j];
        }
    }
    for(int i = 1; i <= 5; i++)
        cout << res[i] << " ";
    cout << '\n';
    cout << sum;
}