#include<bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

long long a[200005];
int f[130][130];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
	for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            i--; n--;
        }
    }
    if (n > 120) {
        cout << 3;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            f[i][j] = 1e9;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if ((a[i] & a[j]) && i != j)
                f[i][j] = f[j][i] = 1;
    
    int ans = 1e9;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < k; i++)
            for(int j = 0; j < i; j++)
                if ((a[i] & a[k]) && (a[j] & a[k]))
                    ans = min(ans, f[i][j] + 2);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    }
    if (ans == 1e9)
        cout << "-1";
    else cout << ans;
}