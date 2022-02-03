#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n1, n2, n3, n;
int a[MAXN], f[MAXN];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n1 >> n2 >> n3;
    for(int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    for(int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        a[x] = 2;
    }

    for(int i = 0; i < n3; i++) {
        int x;
        cin >> x;
        a[x] = 3;
    }
    n = n1 + n2 + n3;
    for(int i = 1; i <= n; i++) {
        int temp = 0;
        for(int j = 1; j <= a[i]; j++)
            temp = max(temp, f[j] + 1);
        f[a[i]] = temp;
    }

    cout << n - max(f[1], max(f[2], f[3]));
    return 0;
}