#include <bits/stdc++.h>

using namespace std;

const int LIM = 5e5;
const int MOD = 998244353;

vector < int > sg[3], fw, f;
vector < int > pos[LIM + 1];
int pp2[2 * LIM + 1];

void update(int t, int id, int l, int r, int pos, int val) {
    if (l == r && pos == l) {
        sg[t][id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(t, id * 2, l, mid, pos, val);
    else update(t, id * 2 + 1, mid + 1, r, pos, val);
    sg[t][id] = (sg[t][id * 2] + sg[t][id * 2 + 1]) % MOD;
}

int get(int t, int id, int l, int r, int u, int v) {
    if (v < l || u > r)
        return 0;
    if (u <= l && r <= v)
        return sg[t][id];
    int mid = (l + r) >> 1;
    return (get(t, id * 2, l, mid, u, v) + get(t, id * 2 + 1, mid + 1, r, u, v)) % MOD;
}

int bs(int y, int p) {
    int l = 0, r = pos[y].size() - 1;
    int ans = pos[y].size();
    while (l <= r) {
        int mid = (l + r) >> 1;
        // cout << mid << " " << pos[y][mid] << " " << p << endl;
        if (pos[y][mid] >= p) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int calc(int x, int p) {
    int y = x - 2;
    int res = pos[y].size() - bs(y, p);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    pp2[0] = 1;
    for (int i = 1; i <= LIM * 2; i++)
        pp2[i] = (pp2[i - 1] * 2) % MOD;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++) {
            sg[i].resize(4 * n + 4);
            fill(sg[i].begin(), sg[i].end(), 0);
        }
        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i + 1);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        // 1 permutation sequence
        int res = (pp2[pos[1].size()] - 1 + MOD) % MOD;
        for (int z = 0; z < a.size(); z++) {
            bool flag = true;
            int i = a[z];
            if (z == 0 && i != 0)
                break;
            if (z > 0 && a[z] - 1 > a[z - 1])
                flag = false;
            for (int j = 0; j < pos[i].size(); j++) {
                int p = pos[i][j];
                if (flag) {
                    int sumCur = 0, sumPre = 0;
                    sumCur = get(i % 3, 1, 1, n, 1, p);
                    if (i > 0)
                        sumPre = get((i - 1) % 3, 1, 1, n, 1, p);
                    int sum = (sumCur + sumPre) % MOD;
                    if (i == 0)
                        sum = (sum + 1) % MOD;
                    update(i % 3, 1, 1, n, p, sum);
                    res = (res + sum) % MOD;
                }
                if (i >= 2) {
                    if (flag || (!flag && a[z] - 2 == a[z - 1])) {
                        int sumPrePre = get((i - 2) % 3, 1, 1, n, 1, p);
                        res += (1ll * sumPrePre * (pp2[calc(i, p) + pos[i].size() - j - 1]) % MOD) % MOD;
                        res %= MOD;
                    }
                }
            }
            if (!flag)
                break;
            if (i >= 2) {
                for (int j = 0; j < pos[i - 2].size(); j++) {
                    int p = pos[i - 2][j];
                    update((i - 2) % 3, 1, 1, n, p, 0);
                }
            }
        }
        cout << res << '\n';
        for (int i = 0; i < n; i++)
            pos[a[i]].clear();
    }
    return 0;
}