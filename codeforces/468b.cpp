#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

map <int, int> mp;
     
int n, a, b;
int root[MXN], lab[MXN], grp[MXN], p[MXN];

int findRoot(int x) { 
    if (root[x] == x)
        return x;
    return root[x] = findRoot(root[x]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        mp[p[i]] = root[i] = i;
    }
    
    for(int i = 1; i <= n; i++) {
        if (mp.count(a - p[i])) {
            root[findRoot(mp[a - p[i]])] = findRoot(i);
            lab[i] |= 1;
        }
        if (mp.count(b - p[i])) {
            root[findRoot(mp[b - p[i]])] = findRoot(i);
            lab[i] |= 2;
        }
    }
    for(int i = 1; i <= n; i++)
        grp[i] = 3;
    for(int i = 1; i <= n; i++) 
        grp[findRoot(i)] &= lab[i];
    for(int i = 1; i <= n; i++)
        if (grp[i] == 0) {
            cout << "NO";
            return 0;
        }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << (grp[findRoot(i)] + 1) % 2 << " ";
    }
}