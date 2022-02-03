#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, m;
vector < int > switches[MXN], sw[MXN];
int r[MXN];
bool marked[MXN];

bool check(int sw1, int sw2, int type) {
    cout << sw1 << " * " << sw2 << " * " << type << '\n';
    for(int i = 0; i < switches[sw2].size(); i++) {
        int x = switches[sw2][i];
        cout << x << " ";
        marked[x] = false;
    }
    cout << endl;
    for(int i = 0; i < switches[sw1].size(); i++) {
        int x = switches[sw1][i];
        cout << x << " ";
        marked[x] = true;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << marked[i] << " "; cout << endl;
    for(int i = 0; i < switches[sw2].size(); i++) {
        int x = switches[sw2][i];
        cout << x << " " << marked[x] << " " << r[x] << endl;
        if (type == 1) {
            if (marked[x] == 1 && r[x] == 0)
                return false;
        } else {
            if (marked[x] == 0 && r[x] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> r[i];
    for(int i = 0; i < m; i++) {
        int len;
        cin >> len;
        for(int j = 0; j < len; j++) {
            int x;
            cin >> x;
            x--;
            switches[i].push_back(x);
            sw[x].push_back(i);
            //cout << x << " " << j << endl;
        }
    }

    //cout << check(sw[0][0], sw[0][1], r[0]) << endl; 

    for(int i = 0; i < n; i++) {
        if (!check(sw[i][0], sw[i][1], r[i]) && !check(sw[i][1], sw[i][0], r[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}