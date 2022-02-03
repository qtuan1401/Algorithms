#include<bits/stdc++.h>

using namespace std;

const int MXN = 5e3 + 10;

string s[MXN];
int pos[MXN], a[MXN];
int n, m;

int main() {	
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> s[i];
    int res = 0;
    for(int i = 0; i < m; i++) {	
        memset(a, 0, sizeof(a));	
        for(int j = 0; j < n; j++) 
            if (s[j][i] == '1') {
                a[++pos[j]]++;
            } else 
                pos[j] = 0;
        for(int i = m; i >= 0; i--) {
            a[i] += a[i + 1];
            res = max(res, a[i] * i);
        }
    }
    cout << res;
}