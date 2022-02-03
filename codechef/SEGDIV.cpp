#include <bits/stdc++.h>

using namespace std;

vector < int > prime, num;

void sieve(int n) {
    prime.resize(n + 1);
    for(int i = 2; i * i <= n; i++) {
        if (prime[i] == false) {
            for(int j = i * i; j <= n; j += i)
                prime[j] = true;
        }
    }
    for (int i = 3; i <= n; i++)
        if (prime[i] == false)
            num.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    int n = 500;
    vector < int > ans(n + 1);
    ans[1] = 1;
    vector < bool > marked(1e5 + 1, false);
    marked[1] = 1;
    for (int i = 2; i <= n; i++) {
        bool ok = false;
        int cur = 1;
        while (!ok) {
            while (cur < 100000 && marked[cur] == true) cur++;
            ans[i] = cur;
            ok = true;
            long long sum = ans[i];
            for (int j = i - 1; j >= 1; j--) {
                sum += ans[j];
                if (sum % (i - j + 1) == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) cur++;
            else marked[cur] = true;
        }
    }
    
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}