#include <bits/stdc++.h>

using namespace std;

const int N = 4e5+5;

struct node{
    int left, right, cnt;
} t[N*20];

int n,q;
int a[N],b[N];
int nNode;
vector<int> v;
int ver[N];

int update(int l, int r, int pos, int pre) {
    if (l == r) {
        ++nNode;
        t[nNode].cnt++;
        t[nNode].left = t[nNode].right = 0;
        return nNode;
    }
    int mid = (l + r) >> 1;
    int cur = ++nNode;
    if (pos <= mid) {
        t[cur].left = update(l, mid, pos, t[pre].left);
        t[cur].right = t[pre].right;
        t[cur].cnt = t[t[cur].left].cnt + t[t[cur].right].cnt;
    } else {
        t[cur].left = t[pre].left;
        t[cur].right = update(mid + 1, r, pos, t[pre].right);
        t[cur].cnt = t[t[cur].left].cnt + t[t[cur].right].cnt;
    }

    return cur;
}

int get(int v1, int v2, int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int val = t[t[v2].left].cnt - t[t[v1].left].cnt;
    if (val >= k)
        get(t[v1].left, t[v2].left, l, mid, k);
    else
        get(t[v1].right, t[v2].right, mid + 1, r, k - val);
}

int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
	cin >> q;
    sort(v.begin(), v.end());

    for(int i=1;i<=n;i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    
    ver[0] = 0;
    for(int i=1;i<=n;i++) {
        ver[i] = update(1, n, a[i], ver[i - 1]);
    }
    int l, r, x;
    while (q--) {
        cin >> l >> r >> x;
        int k = get(ver[l - 1], ver[r], 1, n, x);
        cout << v[k - 1] << "\n";
    }
    return 0;
}