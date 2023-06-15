#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        int vtx = 1;
        vector < int > vst(n + 1, -1);
        vst[1] = true;
        while (vtx != n) {
            int k;
            cin >> k;
            int nxt = -1;
            vector < int > edges(k);
            for (int i = 0; i < k; i++) {
                cin >> edges[i];
            } 

            for (int i = k - 1; i >= 0; i--) {
                int v = edges[i];
                if (vst[v] == -1) {
                    vst[v] = vtx;
                    nxt = v;
                    break;
                }
            }

            if (nxt != -1) {
                cout << nxt << endl;
                cout << flush;
                vtx = nxt;
            } else {
                cout << vst[vtx] << endl;
                cout << flush;
                vtx = vst[vtx];
            }
            
        }
    }
    return 0;
}