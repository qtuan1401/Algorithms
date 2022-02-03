#include <bits/stdc++.h>

using namespace std;

const int MXN = (1 << 12) + 10;

int n, m, q;
int w[15], cnt[MXN], wu[MXN][105];

inline int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) 
        cin >> w[i];
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int num = 0;
        for(int j = 0; j < n; j++)
            num += (1 << j) * char(s[j] - '0');
        //cout << num << " ";
        cnt[num]++;
    }
    //for(int i = 0; i < (1 << n); i++)
    //    cout << cnt[i] << " ";
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < (1 << n); j++) {
            //cout << i << " " << j << " " << cnt[j] << endl;
            if (cnt[j] > 0) {
                int sum = 0;
                for(int k = 0; k < n; k++)
                    if (getBit(i, k) == getBit(j, k))
                        sum += w[k];
                if (sum <= 100)
                    wu[i][sum] += cnt[j];
            }
        }
    }
    //cout << wu[0][20] << endl;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 1; j <= 100; j++)
            wu[i][j] += wu[i][j - 1];
    }
    while (q--) {
        string s;
        int k;
        cin >> s >> k;
        int num = 0;
        for(int i = 0; i < n; i++)
            num += (1 << i) * (s[i] - '0');
        cout << wu[num][k] << '\n';
    }
    return 0;
}  