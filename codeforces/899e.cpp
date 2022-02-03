#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

struct node {
    int val, l, r;
    node(const int & val = 0, const int & l = 0, const int & r = 0) : val(val), l(l), r(r) {}
    bool operator < (const node & temp) const {
        if (val == temp.val)
            return l < temp.l;
        return (val > temp.val);
    }
};

set < node > seg;
bool marked[MXN];
int pL[MXN], pR[MXN], ll[MXN], rr[MXN], a[MXN], val[MXN];
int n;

int findLeft(int x) {
    //cout << x << " " << pL[x] << " " << marked[pL[x]] << endl;
    if (x == 0)
        return 0;
    if (!marked[x])
        return x;
    x = ll[x];
    return pL[x] = findLeft(pL[x]);
}

int findRight(int x) {
    //cout << x << " " << pR[x] << " " << marked[pR[x]] << " " << rr[x] << endl;
    if (x == n + 1)
        return n + 1;
    if (!marked[x])
        return x;
    x = rr[x];
    return pR[x] = findRight(pR[x]);   
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1;
    a[n + 1] = a[n] + 1;
    for(int i = 2; i <= n + 1; i++) {
        if (a[i] != a[i - 1]) {
            int r = i - 1;
            seg.insert(node(r - l + 1, l, r));
            pL[l] = l - 1;
            pR[r] = r + 1;
            ll[r] = l;
            rr[l] = r;
            val[l] = val[r] = r - l + 1;
            //cout << l << " " << r << endl;
            l = i;
        } 
    }
    //return 0;
    marked[0] = marked[n + 1] = 1;
    pR[n + 1] = n + 1;
    int res = 0;
    //if (n == 200000)
    //    cout << seg.size() << endl;
    while (seg.size()) {
        res++;
        node cur = *seg.begin();
        seg.erase(seg.begin());
        marked[cur.l] = marked[cur.r] = true;
        //cout << cur.l << " " << cur.r << endl;
        int l = findLeft(pL[cur.l]);
        int r = findRight(pR[cur.r]);
        //cout << l << " " << r << " " << a[l] << " " << a[r] << " " << marked[l] << " " << marked[r] << endl;
        //return 0;
        if (!marked[l] && !marked[r] && a[l] == a[r]) {
            node p1 = node(val[l], ll[l], l);
            node p2 = node(val[rr[r]], r, rr[r]);
            int nVal = val[l] + val[rr[r]];
            int nl = ll[l], nr = rr[r];
            val[nl] = val[nr] = nVal;
            ll[nr] = nl;
            rr[nl] = nr;
            //cout << nl << " * " << nr << " * " << nVal << endl;
            //return 0;
            seg.erase(seg.find(p1));
            seg.erase(seg.find(p2));
            seg.insert(node(nVal, nl, nr));
        }         
    }
    cout << res;
    return 0;
}