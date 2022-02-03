#include <bits/stdc++.h>

using namespace std;

const int MAXN = 31;

long long pp[MAXN], sum[MAXN];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    sum[0] = pp[0] = 1;
    for(int i = 1; i <= 30; i++)
        pp[i] = pp[i - 1] * 4;
    for(int i = 1; i <= 30; i++)
        sum[i] = sum[i - 1] + pp[i]; 
    while (T--) {
        long long n, k;
        cin >> n >> k;
        //cout << n << " * " << k << endl;
        if (n == 1) {
            if (k == 1) 
                cout << "YES 0\n";
            else 
                cout << "NO\n";
            continue;
        }
        if (k == 1) {
            cout << "YES " << n - 1 << '\n';
            continue;
        }
        if (k > sum[min(30ll, n - 1)]) {
            cout << "NO\n";
            continue;
        }
        k--;
        //long long tot = sum[min(n, 30ll)];
        bool found = false;
        int path = 1;
        long long used = 0;
        for(int i = 1; i <= min(n, 31ll); i++) {
            //int path = i * 2 + 1;
            int remain = path * 2 - 1;
            path = path * 2 + 1;
            //cout << k << " " << remain << " " << n - i << endl;
            long long temp = sum[min(30ll, n - i - 1)] * remain;
            if (n - i - 1 < 0)
                temp = 0; 
            //cout << temp << endl;
            if (temp >= k) {
                cout << "YES " << n - i << '\n';
                found = true;
                break;
            }
            k -= temp;
            used += temp;
            if (k <= path && path - k <= used) {
                cout << "YES " << n - i - 1 << '\n';
                found = true;
                break;
            }
            used += path;
            k -= path;
            if (k < 0) {
                cout << "NO\n";
                found = true;
                break;
            }
            //cout << k << endl;
        }
        if (!found)
            cout << "NO\n";
    }
    return 0;
}