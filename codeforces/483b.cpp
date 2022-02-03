#include<bits/stdc++.h>

using namespace std;


inline int calc(int cnt, int x) {
	return (cnt - 1) / (x - 1) * x + (cnt - 1) % (x - 1) + 1;
}

int main() {
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    cout << max(max(calc(cnt1, x), calc(cnt2, y)), calc(cnt1 + cnt2, x * y));
    return 0;
}