#include <bits/stdc++.h>

using namespace std;

string s;

int calc(int x) {
    for (int i = -2; i <= 0; i++)
        if (x + i >= 0 && x + i + 2 < s.size())
            if (s[x + i] == 'a' && s[x + i + 1] == 'b' && s[x + i + 2] == 'c') return 1;
    return 0;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q >> s;

    int sum = 0;
    for (int i = 2; i < n; i++) 
        sum += (s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c');
    
    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        sum -= calc(x);
        s[x] = c;
        sum += calc(x);
        cout << sum << '\n';
    }
    return 0;
}