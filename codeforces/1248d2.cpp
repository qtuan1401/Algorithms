#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e5 + 10;

int sum[MXN];
string s;
int n;

int calc(int l, int r, string s) {
    cout << s << endl;
    int cnt = 0, sum = 0;
    for (int i = l + 1; i < r; i++) {
        if (s[i] == '(')
            sum++;
        else
            sum--;
        if (sum == 0)
            cnt++;
        cout << sum << " ";
    }
    cout << endl;
    return cnt;
}

int check() {
    vector < int > mn(n);
    for (int i = 0; i < n; i++) {
        mn[i] = n;
    }
    mn[n - 1] = sum[n - 1];
    for (int i = n - 2; i >= 0; i--)
        mn[i] = min(mn[i + 1], sum[i]);
    if (sum[n - 1] == 0 && mn[0] == 0)
        return 1;
    // cout << sum[n - 1] << endl;
    if (sum[n - 1] != 0)
        return 0;
    bool ok = false;
    int x = sum[0];
    for (int i = 1; i < n; i++) {
        if (mn[i] - sum[i - 1] >= 0 && sum[n - 1] - sum[i - 1] + x >= 0) {
            ok = true;
            break;
        }
        x = min(x, mn[i]);
    }
    if (ok == false)
        return 0;
    return 2;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i > 0)
            sum[i] += sum[i - 1];
        if (s[i] == '(')
            sum[i]++;
        else
            sum[i]--;
    }

    if (check() == 0) {
        cout << 0 << '\n';
        cout << 1 << " " << 1;
        return 0;
    }

    if (check() == 1) {
        cout << calc(-1, n, s) + 1 << '\n';
        cout << 1 << " " << 1;
        return 0;
    }
    int mn = n, mx = 1;
    for (int i = 0; i < n; i++) {
        mn = min(mn, sum[i]);
    }
    int posMn = 0, posMx = 0;
    for (int i = 0; i < n; i++) {
        if (mn == sum[i])
            posMn = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (sum[i] == 0)
            break;
        mx = max(mx, sum[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (sum[i] - sum[posMn] <= 0) {
            posMx = i + 1;
            break;
        }
    }

    vector < int > close, open;
    for (int i = posMn; i >= 0 && mn < 0; i--) {
        if (sum[i] == mn) {
            mn++;
            close.push_back(i);
        }
    }

    for (int i = posMx; i < n; i++) {
        if (sum[i] - sum[posMn] == mx) {
            mx++;
            open.push_back(i);
        }
    }
    // cout << posMx << " " << posMn << endl;
    int rl = 0, rr = 0;
    string s1 = "";
    for (int i = posMn + 1; i < n; i++)
        s1 += s[i];
    for (int i = 0; i < posMn; i++)
        s1 += s[i];
    mx = calc(0, n, s1);
    // cout << close.size() << " " << open.size() << endl;
    for (int i = 0; i < min(2, (int)close.size()); i++)
        for (int j = 0; j < min(2, (int)open.size()); j++) {
            swap(s[close[i]], s[open[j]]);
            int l = -1, r = n;
            if (i + 1 < close.size())
                l = close[i + 1];
            if (j + 1 < open.size())
                r = open[j + 1];
            cout << l << " " << r << " " << close[i] << " " << open[j] << endl;
            int temp = calc(l, r, s);
            if (mx < temp + 1) {
                rl = close[i];
                rr = open[j];
                mx = temp + 1;
            }
            swap(s[close[i]], s[open[j]]);
        }
    
    cout << mx << '\n';
    cout << rl + 1 << " " << rr + 1;
    return 0;
}