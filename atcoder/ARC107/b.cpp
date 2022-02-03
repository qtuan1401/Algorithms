#include <bits/stdc++.h>

using namespace std;

int n, k;
long long res;

int main() {
    cin >> n >> k;
    for(int ab = 2; ab <= 2 * n; ab++) {
        int cd = ab - k;
        if (cd < 2)
            continue;
        int s1 = ab - 1, s2 = cd - 1;
        if (ab > n)
            s1 = max(0, 2 * n - ab + 1);
        if (cd > n)
            s2 = max(0, 2 * n - cd + 1);
        //cout << ab << " " << s1 << " " << cd << " " << s2 << " " << n * 2 << endl;
        //cout << ab << " " << ab - max(1, ab - n) << endl;
        res += 1ll * s1 * s2; 
    }
    cout << res;
    return 0;
}

