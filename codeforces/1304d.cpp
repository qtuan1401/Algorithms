#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

int T, n;
int a[md], f[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        int pre = 0, num = n;
        for(int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] == '>') {
                for(int j = i; j >= pre; j--)
                    a[j] = num--;
                pre = i + 1;
            }
        }
        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        pre = 0, num = 1;
        for(int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] == '<') {
                for(int j = i; j >= pre; j--)
                    a[j] = num++;
                pre = i + 1;
            }
        }
        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}