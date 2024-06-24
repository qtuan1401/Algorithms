#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;
vector < int > a, p;

int n, k;

long long calc(int pos) {
    // cout << pos << '\n';
    vector < int > marked(n, 0);
    // for (int i = 0; i < n; i++) cout << marked[i] << " ";
    // cout << endl;
    int pMx = pos, mx = a[pos];
    while (!marked[pos]) {
        marked[pos] = 1;
        pos = p[pos];
        if (a[pos] > mx) {
            mx = a[pos];
            pMx = pos;
        }
    }

    long long res = 0, sum = 0;
    int s = pos;
    for (int i = 0; i < k; i++) {
        res = max(res, 1ll * (k - i) * a[s] + sum);
        sum += a[s];
        if (s == pMx) break;
        s = p[s];
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int pb, ps;
        cin >> n >> k >> pb >> ps;
        pb--; ps--;
        a.clear();
        a.resize(n, 0);
        p.clear();
        p.resize(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // for (int i = 0; i < n; i++) cout << p[i] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++) cout << a[i] << " ";
        // cout << endl;
        
        long long sumB = calc(pb);
        long long sumS = calc(ps);
        if (sumB > sumS) cout << "Bodya\n";
        else if (sumB < sumS) cout << "Sasha\n";
        else cout << "Draw\n";
    }
    return 0;
}