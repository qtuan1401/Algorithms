#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 1;

vector < int > adjr[MXN], adjg[MXN];

int markr[MXN], markg[MXN], cntg[MXN], cntr[MXN];
int n;
string color;

void dfsr(int u, int cnt) {
    markr[u] = cnt;
    for (int & v : adjr[u]) {
        if (markr[v] > 0) continue;
        dfsr(v, cnt);
    }
}

void dfsg(int u, int cnt) {
    markg[u] = cnt;
    for (int & v : adjg[u]) {
        if (markg[v] > 0) continue;
        dfsg(v, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> color;
        for (int i = 0; i <= n; i++) {
            adjr[i].clear();
            adjg[i].clear();
            markg[i] = markr[i] = cntg[i] = cntr[i] = 0;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            // cout << u << " " << v << " " << color[u] << " " << color[v] << endl;
            if ((color[u] == 'G' || color[u] == 'B') && (color[v] == 'G' || color[v] == 'B')) {
                adjg[u].push_back(v);
                adjg[v].push_back(u);
                // cout << "G" << " " << u << " " << v << endl;
            } else if ((color[u] == 'R' || color[u] == 'B') && (color[v] == 'R' || color[v] == 'B')) {
                adjr[u].push_back(v);
                adjr[v].push_back(u);
                // cout << "R" << " " << u << " " << v << endl;
            }
        }

        int g = 0, r = 0;            

        for (int i = 0; i < n; i++)
            if (markr[i] == 0)
                dfsr(i, ++r);

        for (int i = 0; i < n; i++)
            if (markg[i] == 0)
                dfsg(i, ++g);

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (color[i] != 'B') continue;
            cntr[markr[i]]++;
            cntg[markg[i]]++;
            // cout << i << " " << cntg[markg[i]] << " " << cntr[markr[i]] << " " << " " << markr[i] << " " << markg[i] << endl;
            if (cntr[markr[i]] > 1 || cntg[markg[i]] > 1) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}