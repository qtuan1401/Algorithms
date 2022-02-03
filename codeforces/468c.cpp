#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "NO";
        return 0;
    }
    if (n % 2 == 0) {
        cout << "YES\n";
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "4 * 6 = 24\n";
        for(int i = 5; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = " << 1 << '\n';
            cout << "24 * 1 = 24\n";
        }
    } else {
        cout << "YES\n";
        cout << "2 - 1 = 1\n";
	    cout << "1 + 3 = 4\n";
	    cout << "4 * 5 = 20\n";
	    cout << "20 + 4 = 24\n";
        for(int i = 6; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = " << 1 << '\n';
            cout << "24 * 1 = 24\n";
        }
    }
    return 0;
} 