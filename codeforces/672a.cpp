#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
    string res;
    for(int i = 1; i <= n; i++)
        res += to_string(i);
    cout << res[n - 1];
    return 0;
}