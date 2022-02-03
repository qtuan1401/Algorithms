#include <iostream>
#include <vector>

using namespace std;

int n, m, sum;
int cnt[200005];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    vector < vector < int > > a = vector < vector < int > > (n, vector < int > (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++)
            cnt[i] = 0;
        for(int i = 0; i < n; i++) {
            if (a[i][j] % m != (j + 1) % m || a[i][j] > n * m)
                continue;
        //    cout << a[i][j] << " " << i << " " << i - a[i][j] / m << endl;
            cnt[(i - (a[i][j] / m) + (a[i][j] % m == 0) + n) % n]++;
        }
        //cout << cnt[0] << "*" << endl;
        int ans = n;
        for(int i = 0; i < n; i++)
            ans = min(ans, i + n - cnt[i]);
        //cout << ans << endl;
        sum += ans;
    }
    cout << sum;
    return 0;
}