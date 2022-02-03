#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

string s;

inline int calc(int n) {
    int res = 1;
    for(int i = 0; i < n; i++) {
        res = (res * 2) % MOD;
    } 
    return res;
}

int f(int x) {
	if (x == s.size()) 
        return 0;
	return (2 * f(x + 1) % MOD + (s[x] == '1') * calc(2 * (s.size() - x - 1))) % MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
	cin >> s;
	cout << f(0);
    return 0;	
}
