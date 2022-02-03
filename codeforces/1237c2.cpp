#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;
const int oo = -1e9;

typedef pair < int, int > II;


struct point {
    int x, y, z, id;
    void input(int i) {
        cin >> x >> y >> z;
        id = i;
    }
    bool operator < (const point & p) const {
        if (p.z == z) {
            if (p.x == x)
                return y < p.y;
            return x < p.x;
        } 
        return z < p.z;
    }
};

point points[MAXN];
int n;
vector < point > remain;
vector < II > ans; 

void calc(vector < point > p) {
    //cout << p.size() << endl;
    //for(int i = 0; i < p.size(); i++)
    //    cout << p[i].x << " " << p[i].y << " "<< p[i].z << " " << p[i].id << endl;
    stack < point > pre;
    pre.push(p[0]);
    for(int i = 1; i < p.size(); i++) {
        if (pre.size()) {
            point cur = pre.top(); pre.pop();
            if (p[i].x == cur.x) {
                ans.push_back(II(cur.id, p[i].id));
            } else if (i == p.size() - 1 || p[i + 1].x != p[i].x) {
                ans.push_back(II(cur.id, p[i].id));
            } else {
                pre.push(cur);
                pre.push(p[i]);
            }
        } else 
            pre.push(p[i]);
    }
    //cout << pre.x << endl;
    if (pre.size()) 
        remain.push_back(pre.top());
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        points[i].input(i + 1);
    sort(points, points + n);
    //for(int i = 0; i < n; i++)
    //    cout << points[i].x << " " << points[i].y << " "<< points[i].z << endl;
    int i = 0;
    vector < point > p;
    while (i < n) {
        p.clear();
        int z = points[i].z;
        for( ; i < n; i++)
            if (points[i].z == z)
                p.push_back(points[i]);
            else break;
        calc(p);
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << '\n';
    //cout << remain.size() << endl;
    for(int i = 0; i < remain.size(); i += 2)
        cout << remain[i].id << " " << remain[i + 1].id << '\n';
    return 0;
}
