#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

string s[105];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                    continue;
                cnt += (s[ni][nj] == 'o');
            }
            res += (cnt % 2 == 0);
        }
    }
    cout << (res == n * n ? "YES" : "NO");
    return 0;
}