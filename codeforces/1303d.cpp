#include <bits/stdc++.h>
 
using namespace std;
 
int getBit(long long x, int i) {
    return ((x >> i) & 1);
}
 
int a[100005], g[100], cnt[100];
 
int m, T, res = 0;
long long n;
 
int main() {
    //freopen("test.in", "r", stdin); 
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        res = 0;
        long long n;
        cin >> n >> m;
        for(int i = 0; i < 64; i++)
            cnt[i] = g[i] = 0;
        for(int i = 1; i <= m; i++) {
            cin >> a[i];
            cnt[int(log2(a[i]))]++;
        }
        /*for(int i = 0; i < 64; i++)
            cout << cnt[i] << " ";
        cout << endl;*/
        for(int i = 0; i < 64; i++)
            g[i] = getBit(n, i);
        /*for(int i = 0; i < 64; i++)
            cout << g[i] << " ";
        cout << endl;*/
        int remain = 0;
        for(int i = 0; i < 64; i++) {
            if (g[i] == 1 && cnt[i] == 0)
                remain++;
            else if (cnt[i] > 0) {
                if (g[i] == 1)
                    cnt[i]--, g[i] = 0;
                if (cnt[i] > 0 && remain > 0) {
                //    cnt[i]--;
                    for(int j = i - 1; j >= 0; j--) {
                        cnt[j] = 2;
                        cnt[j + 1]--;
                        if (g[j] == 1)
                            cnt[j]--, remain--, g[j] = 0;
                        if (remain == 0) {
                            for(int k = j; k < i; k++) {
                                cnt[k + 1] += cnt[k] / 2;
                                cnt[k] = 0;
                            }
                            //cout << i << " " << j << endl;
                            res += (i - j);
                            break;
                        }
                    }
                }
            }
            /*cout << remain << " " << res << endl;
            for(int i = 0; i < 64; i++)
                cout << g[i] << " ";
            cout << endl;
            for(int i = 0; i < 64; i++)
                cout << cnt[i] << " ";
            cout << endl << endl;*/
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] = 0;
        }
        bool ok = true;
        for(int i = 0; i < 64; i++)
            if (g[i] > 0)
                ok = false;
        if (!ok)
            cout << "-1\n";
        else cout << res << '\n';
    }
    return 0;
}