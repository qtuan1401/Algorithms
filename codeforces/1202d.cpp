#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e5;
 
int cnt[MAXN];
 
int findNum(int n) {
    int x = int(sqrt(n * 2 + 10));
    while (x * (x - 1) / 2 > n)
        x--;
    return x;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int x = 0;
        int m = findNum(n);
        for(int i = 0; i < m; i++)
            cnt[i] = 0;
        //cout << m << endl;
        do {
            x = findNum(n);
            cnt[m - x]++;
            n -= x * (x - 1) / 2;
        } while (n > 0);
        string ans = "";
        for(int i = 0; i < m; i++) {
            for(int j = 1; j <= cnt[i]; j++)
                cout << "1";
            cout << "3";
        }
        cout << "7\n";
    }
    return 0;
}