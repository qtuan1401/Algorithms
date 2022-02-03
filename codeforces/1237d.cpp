#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int st[MAXN][20], st1[MAXN][20], a[MAXN], b[MAXN], len[MAXN];
int n;

void build() {
    for(int i = 0; i < n; i++)
        st[i][0] = a[i];
    for(int k = 1; (1 << k) <= n; k++)
        for(int i = 0; i + (1 << k) - 1 < n; i++)
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
}

int get(int l, int r) {
    if (l > r)
        return 0;
    int k = len[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]); 
}

int bsL(int l, int r, int val) {
    int i = l;
    int pos = n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(i, mid) < val) {
            pos = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return pos;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        a[i + 2 * n] = a[i];
    }
    n *= 3;

    build();
    for(int i = 0; i <= n; i++)
        len[i] = log2(i);

    for(int i = 0; i < n; i++) 
        b[i] = bsL(i, n - 1, (a[i] / 2) + a[i] % 2);
   
    for(int i = 0; i < n; i++)
        a[i] = b[i];

    build();
    for(int i = 0; i < n / 3; i++) {
        int pos = a[i];
        if (pos == n + 1)
            pos = n - 1;
        pos = get(i, pos);
        if (pos == n + 1)
            cout << "-1 ";
        else cout << pos - i << " ";
    }
    return 0;
}