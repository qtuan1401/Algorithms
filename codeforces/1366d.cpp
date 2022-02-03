#include <bits/stdc++.h>

using namespace std;

const int MXA = 1e7 + 10;
const int MXN = 5e5 + 10;

typedef pair < int, int > II;

int minPrime[MXA];
int d1[MXN], d2[MXN];

void eratos(int n) {
    for(int i = 2; i * i <= n; i++)
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            for(int j = i * i; j <= n; j += i)
                if (minPrime[j] == 0)
                    minPrime[j] = i;
        }
}

II factorize(int x) {
    II ans = II(0, 0);
    while (x != 1) {
        int temp = minPrime[x];
        if (temp > 0) {
            int sum = 0;
            while (x % temp == 0) {
                x /= temp;
                sum += temp;
            }
            //cout <<  x<< " " << sum << endl;
            if (ans.first == 0)
                ans.first = sum;
            else
                ans.second = sum;
        }
        if (ans.second != 0)
            return ans;
    }
    return II(-1, -1);
}

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    eratos(1e7);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        II facts = factorize(x);
        d1[i] = facts.first;
        d2[i] = facts.second;
    }
    for(int i = 0; i < n; i++)
        cout << d1[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << d2[i] << " ";
    return 0;
}