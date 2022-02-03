#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s = "", res = "-1";
    for(int i = 0; i <= 1000000; i++) {
        int sum = i * 7;
        if (sum <= n && (n - sum) % 4 == 0) {
            //cout << i << " " << sum4 << endl;
            res = s;
        }
        s += "7";
    }
    if (res == "-1") {
        cout << "-1";
        return 0;
    }
    for(int i = 1; i <= (n - 7 * res.size()) / 4; i++)
        cout << "4";
    cout << res;
    return 0;
}