#include <bits/stdc++.h>

using namespace std;

int a[] = {0, 1, 2, 1, 0, 2, 1, 2, 0, 2, 1, 0, 2, 0, 1, 0, 2, 1};
int x, n;

int main() {
    cin >> n >> x;
	cout << a[n % 6 * 3 + x];
}
