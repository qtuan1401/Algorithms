#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int LIM = 2e5;

struct node {
    int l, r, cnt;
    bool operator < (const node & a) const {
        return l < a.l; 
    }
} a[MAXN], cnt[MAXN];

int n, q, sum, len;
int mx[MAXN];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i <= LIM; i++)
        cnt[i].l = 1e9;    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x].l = min(cnt[x].l, i + 1);
        cnt[x].r = max(cnt[x].r, i + 1);
        cnt[x].cnt++;
    }
    for(int i = 1; i <= LIM; i++)
        if (cnt[i].cnt > 0) {
            a[++len] = cnt[i];
        }
    sort(a + 1, a + 1 + len);
    int sumMax = 0;
    for(int i = 1; i <= len; i++) {
        sum += a[i].cnt;
        if (a[i].l <= a[i - 1].r) {
            a[i].r = max(a[i].r, a[i - 1].r);
            sumMax -= mx[i - 1];
            mx[i] = max(a[i].cnt, mx[i - 1]);
            sumMax += mx[i];
        } else {
        //    posR = a[i].r;
            sumMax += mx[i] = a[i].cnt;
        }
    }
    cout << sum - sumMax;
    return 0;
}