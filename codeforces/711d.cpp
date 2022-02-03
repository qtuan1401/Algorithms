#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int a[MXN], vst[MXN], f[MXN], cnt[MXN];
int id;

void findCycle(int u) {
	cnt[id]++;
    vst[u] = 3;
	if (vst[a[u]] == 3) 
        return ;
	findCycle(a[u]);
}

void dfs(int u) {
    vst[u] = 1;
    int v = a[u];
    if (vst[v] == 0) 
        dfs(v);
    else if (vst[v] == 2) {
        vst[u] = 2;
        return ;
    } else {
        findCycle(u);
        id++;
    }
    vst[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);
    int n;
	cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		f[i] = (f[i - 1] * 2) % MOD;
	int ans = 1;
    for(int i = 1; i <= n; i++)
        if (vst[i] == 0)
            dfs(i);
	
    int tot = n;
	for(int i = 0; i < id; i++) {
		tot -= cnt[i];
		ans = (1ll * ans * (f[cnt[i]] - 2 + MOD)) % MOD;
	}
    ans = (1ll * ans * f[tot]) % MOD;
    cout << ans;
	return 0;
}