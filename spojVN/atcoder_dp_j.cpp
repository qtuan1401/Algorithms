#include <bits/stdc++.h>

using namespace std;

vector < vector < vector < double > > > dp;
int n;


double memo(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (x == 0 && y == 0 && z == 0) return 0;
    if (dp[x][y][z] > 0) return dp[x][y][z];

    double res = n + x * memo(x - 1, y, z) + y * memo(x + 1, y - 1, z) + z * memo(x, y + 1, z - 1);
    return dp[x][y][z] = res / (x + y + z);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector < int > cnt(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }

    dp.resize(n + 1, vector < vector < double > > (n + 1, vector < double > (n + 1)));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = -1;
    
    cout << fixed << setprecision(10);
    cout << memo(cnt[0], cnt[1], cnt[2]);
    return 0;
}