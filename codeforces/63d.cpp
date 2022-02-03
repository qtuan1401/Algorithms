#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, n, w, h;
vector < int > x;
vector < vector < char > > ans;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool check(int type) {
    int cnt = 0, cur = 0;
    for (int i = 0; i < w; i++) {
        if ((type == 0 && i % 2 == 0) || (type == 1 && i % 2 == 1)) {
            if (i == min(b, d) && ans[i][0] == '.')
                return false;
            for (int j = 0; j < a + c; j++) {
                if (ans[i][j] == '.')
                    continue;
                cnt++;
                if (cnt > x[cur]) {
                    cnt = 1;
                    cur++;
                }
                ans[i][j] = cur + 'a';
            }
        } else {
            if (i == min(b, d) && ans[i][a + c - 1] == '.')
                return false;
            for (int j = a + c - 1; j >= 0; j--) {
                if (ans[i][j] == '.')
                    continue;
                cnt++;
                if (cnt > x[cur]) {
                    cnt = 1;
                    cur++;
                }
                ans[i][j] = cur + 'a';
            }
        }
    }
    return true;
}

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c >> d >> n;
    w = max(b, d); h = c + a;
    ans.resize(w);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            ans[i].push_back('#');
    }

    if (b > d) {
        for (int i = d; i < b; i++) 
            for (int j = a; j < c + a; j++)
                ans[i][j] = '.';        
    } else {
        for (int i = b; i < d; i++)
            for (int j = 0; j < a; j++)
                ans[i][j] = '.';
    }

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    cout << "YES\n";
    if (check(0)) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    } else {
        check(1);
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }
    return 0;
}