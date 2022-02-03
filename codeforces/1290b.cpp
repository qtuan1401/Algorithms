#include <iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int sum[30][MAXN];
string s;
int n, q;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    s = '#' + s;
    for(int i = 1; i <= n; i++) { 
    //    cout << int(s[i] - 'a') << " " << i << endl;
        for(int j = 0; j < 26; j++)
            sum[j][i] += sum[j][i - 1] + (s[i] - 'a' == j);
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++)
            cnt += (sum[i][r] - sum[i][l - 1] > 0);
        if (cnt >= 3)
            cout << "Yes\n";
        else  {
            if (s[l] == s[r])
                cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}