#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n; string s;
    cin >> n >> s;

    vector < int > l(n + 1), r(n + 1);
    l[0] = -1, r[0] = n + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            int ll = l[i];
            if (ll != -1) r[ll] = i + 1; 
            l[i] = i + 1;
            l[i + 1] = ll;
            r[i + 1] = i; 
        } else {
            int rr = r[i];
            if (rr != n + 1) l[rr] = i + 1;
            r[i] = i + 1;
            l[i + 1] = i;
            r[i + 1] = rr;
        }
    }

    for (int i = 0; i <= n; i++)
        if (l[i] == -1) {
            int x = i;
            do {
                cout << x << " ";
                x = r[x];
            } while (x != n + 1);
            break;
        }   
    return 0;
}