#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	string s, s1;
	cin >> s >> s1;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++) {
        a += (s[i] == '+');
        b += (s[i] == '-');
    }
    for(int i = 0; i < s1.size(); i++) {
        a -= (s1[i] == '+');
        b -= (s1[i] == '-');
    }
	if (a < 0 || b < 0) {
        cout << 0;
        return 0; 
    }
    double res = 1;
    for(int i = b + 1; i <= a + b; i++) {
        res = i * res / (i - b);
    }
    res /= (1 << (a + b));
	cout << fixed << setprecision(15);
    cout << res;
    return 0;
}
