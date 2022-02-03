#include <bits/stdc++.h>

using namespace std;

int a[55], b[55];
int n;

int findGcd(int x, int y) {
    if (y == 0)
        return x;
    return findGcd(y, x % y);
}

int main() {
    ios_base::sync_with_stdio(0);
    // freopen("test.txt", "r", stdin);
    cin >> n;
    int mnA = 1e9;
    int mnB = 1e9;
    vector < int > factA, factB;
    factA.resize(1e6);
    factB.resize(1e6);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        vector < int > fact1, fact2;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) 
                fact1.push_back(j);
            if (a[i] / j != j)
                fact1.push_back(a[i] / j);
        }
        for (int j = 1; j * j <= b[i]; j++) {
            if (b[i] % j == 0)
                fact2.push_back(j);
            if (b[i] / j != j)
                fact2.push_back(b[i] / j);
        }
        if (1ll * factA.size() * factB.size() > 1ll * fact1.size() * fact2.size()) {
            factA = fact1;
            factB = fact2;
        }
    }
    
    // cout << factA.size() << " " << factB.size() << endl;

    long long res = 0;
    for (int i = 0; i < factA.size(); i++) {
        int x = factA[i];
        for (int j = 0; j < factB.size(); j++) {
            int y = factB[j];
            // cout << x << " " << y << endl;
            if (1ll * x * y <= res)
                continue;
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (!(a[k] % x == 0 && b[k] % y == 0) &&
                    !(a[k] % y == 0 && b[k] % x == 0)) {
                        ok = false;
                        break;
                    }
            }
            if (ok)
                res = max(res, 1ll * x * y);
        }
    }
    
    long long gcd = findGcd(a[0], b[0]);
    // cout << gcd << endl;
    // cout << findGcd(a[0], b[0]) << " " << a[0] << " " << b[0] << endl;
    for (int i = 1; i < n; i++)
        gcd = findGcd(gcd, findGcd(a[i], b[i]));
    cout << res / gcd;
    return 0;
}