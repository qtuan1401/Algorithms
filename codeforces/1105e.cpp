#include <bits/stdc++.h>

using namespace std;

int n, m, num;
long long adj[50];

vector < set < int > > v;
map < string, int > mp;
map < long long, int > f;
    
inline long long offBit(long long x, int i) {
    return x & (~(1ll << i));
}

inline long long getBit(long long x, int i) {
    return (x >> i) & 1;
}

int dfs(long long x) {
    //cout << x << endl;
    if (f.find(x) != f.end()) return f[x];
    int bit = 0;
    while (!getBit(x, bit)) bit++;
    //cout << bit << "*" << " " << (x ^ (1ll << bit)) << " " << (x & adj[bit]) << endl;
    int res1 = dfs(x ^ (1ll << bit)), res2 = dfs(x & adj[bit]);
    return f[x] = max(res1, res2 + 1);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            set <int> s;
            v.push_back(s);
        } else {
            string s;
            cin >> s;
            if (mp.find(s) == mp.end()) 
                mp[s] = cnt++;
            v.back().insert(mp[s]);
        }
    }
    //return 0;
    for(int i = 0; i < m; i++)
        adj[i] = (1ll << m) - 1;
    for(int i = 0; i < v.size(); i++)
        for (set < int > :: iterator it1 = v[i].begin(); it1 != v[i].end(); it1++)
            for (set < int > :: iterator it2  = v[i].begin(); it2 != v[i].end(); it2++) {
                int x = *it1, y = *it2;
                //cout << x << " " << y << " " << adj[x] << endl;
                adj[x] = offBit(adj[x], y);
                //cout << x << " " << y << " " << adj[x] << endl;
            }
    //return 0;
    f[0] = 0;
    cout << dfs((1ll << m) - 1);
    return 0;
}