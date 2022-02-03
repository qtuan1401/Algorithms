#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

const string chicken = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

char ans[MAXN][MAXN];
string s[MAXN];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int r, c, k;
        cin >> r >> c >> k;
        int cnt = 0;
        for(int i = 0; i < r; i++) {
            cin >> s[i];
            for(int j = 0; j < c; j++)
                cnt += (s[i][j] == 'R');
            for(int j = 0; j < c; j++)
                ans[i][j] = '#';
        }

        int numRice = cnt / k;
        int remain = cnt % k;
        int id = 0;
        int row = 0, col = 0;
        for(int i = 0; i < k; i++, remain--) {
            int cur = numRice + (remain > 0);
            while (cur > 0) {
                if (s[row][col] == 'R')
                    cur--;
                ans[row][col] = chicken[i];
                if (row % 2 == 1)
                    col--;
                else col++;
                if (col == -1) {
                    col = 0;
                    row++;
                } 
                if (col == c) {
                    col = c - 1;
                    row++;
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (ans[i][j] == '#')
                    ans[i][j] = chicken[k - 1];
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}