#include <bits/stdc++.h>

using namespace std;

const int MXN = 505;

typedef pair < int, int > II;

int a[MXN], b[MXN];

bool check(vector < II > pA, vector < II > pB) {
    for(int i = 0; i < pA.size(); i++)
        if (pA[i] != pB[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        if (n & 1) {
            if (a[n / 2] != b[n / 2]) {
                cout << "no\n";
                continue;
            }
        }
        vector < II > pA, pB;
        //1 2 3 4 5, 4 (0, 1)
        for(int i = 0; i < n / 2; i++) {
            if (a[i] > a[n - i - 1])
                swap(a[i], a[n - i - 1]);
            if (b[i] > b[n - i - 1])
                swap(b[i], b[n - i - 1]);
            pA.push_back(II(a[i], a[n - i - 1]));
            pB.push_back(II(b[i], b[n - i - 1]));
        }
        //for(int i = 0; i < pA.size(); i++)
        //    cout << pA[i].first << " " << pA[i].second << endl;
        //for(int i = 0; i < pB.size(); i++)
        //    cout << pB[i].first << " " << pB[i].second << endl;
        sort(pA.begin(), pA.end());
        sort(pB.begin(), pB.end());
        cout << (check(pA, pB) ? "yes" : "no") << '\n';
    }
    return 0;
}