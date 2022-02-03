#include <bits/stdc++.h>

using namespace std;

int f[10000][10000];
int a[50], b[50];
int n, res, uu, vv;

void try1(int i, int u, int v) {
    //cout << i << endl;
    if (i > n / 2)
        return ;
    //cout << i <<  endl;
    try1(i + 1, u + a[i], v + b[i]);
    f[u + a[i] + 3000][v + b[i] + 3000]++;
    try1(i + 1, u, v);
}

void try2(int i, int u, int v) {
    if (i > n)
        return ;
    //cout << uu << " " << vv <<" " << a[i] << " " << b[i] << endl;
    //cout << uu - (u + a[i]) << " " << vv - (v + b[i]) << endl;
    res += f[uu - (u + a[i]) + 3000][vv - (v + b[i]) + 3000];
    try2(i + 1, u + a[i], v + b[i]);
    try2(i + 1, u, v);
}

int main() {
   // freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i] >> b[i];
        //cout <<
    }
    cin >> uu >> vv;
    f[0 + 3000][0 + 3000] = 1;
    try1(1, 0, 0);
    res = f[uu + 3000][vv + 3000];
    try2(n / 2 + 1, 0, 0);
    cout << res;
    return 0;
}

