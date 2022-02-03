#include <bits/stdc++.h>
    
using namespace std;
    
const int md = 4e5 + 10;
    
int n;
long long f[(1 << 20)], cnt[md][20], num[md];
    
int getbit(int x, int i) {
    return ((x >> i) & 1);
}
    
int onbit(int x, int i) {
    return (x ^ (1 << i));
}
    
int main() {
//    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        --x;
        for(int j = 0; j < 20; j++)
            cnt[x][j] += num[j];
        num[x]++;
    }
    /*for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }*/
    for(int i = 0; i < (1 << 20); i++)
        f[i] = 1e15;
    f[0] = 0;
    for(int mask = 0; mask < (1 << 20); mask++) {
        for(int i = 0; i < 20; i++)  
            if (!getbit(mask, i)) {
                long long temp = 0;
                int now = onbit(mask, i);
                for(int j = 0; j < 20; j++)
                    if (getbit(mask, j))
                        temp += cnt[i][j];
                f[now] = min(f[now], f[mask] + temp);
            }
    }
    cout << f[(1 << 20) - 1];
    return 0;
}