#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MAXN = 1e3 + 10;
const int INF = 1e9;

struct point {
    int x, y, id;
    point(int _x = 0, int _y = 0, int _id = 0) {
        x = _x;
        y = _y;
        id = _id;
    }
};

double calc(point x) {
    if (x.y == 0)
        return INF;
    return 1.0 * x.x / x.y;
}

bool cmp(point a, point b) {
    return calc(a) < calc(b);
}

bool check(point a, point b) {
    return calc(a) == calc(b);
}

int n;
point a[MAXN];
int marked[MAXN][MAXN];

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    
    vector < point > line;
    for(int i = 0; i < n; i++) {
        vector < point > p;
        for(int j = 0; j < n; j++) {
            if (i == j)
                continue;
            p.push_back(point(a[j].x - a[i].x, a[j].y - a[i].y, j));
        }
        sort(p.begin(), p.end(), cmp);
        p.push_back(point(1, INF, 0));
        int mx = max(i, p[0].id);
        int mn = min(i, p[0].id);
        //cout << i << "*******\n";
        //for(int k = 0; k < p.size(); k++)
        //    cout << p[k].x << " " << p[k].y << " " << a[p[k].id].x << " " << a[p[k].id].y << endl;
        //if (i == 5) cerr << cmp(p[0], p[1]) << endl;
        //cout << mx << " " << mn << endl;
        for(int k = 1; k < p.size(); k++) {
            //cout << check(p[k], p[k - 1]) << " " << p[k].id << endl;
            if (!check(p[k], p[k - 1])) {    
                if (!marked[mn][mx]) {
                //    cout << a[mn].x << " * " << a[mn].y << endl;
                //    cout << a[mn].x << " * " << a[mn].y << " " << a[mx].x << " " << a[mx].y << " " << a[mx].x - a[mn].x << " " << a[mx].y - a[mn].y << endl;
                    marked[mn][mx] = true;
                    line.push_back(point(a[mx].x - a[mn].x, a[mx].y - a[mn].y, 0));
                }
                mx = max(i, p[k].id);
                mn = min(i, p[k].id);
            } else {
                mx = max(mx, p[k].id);
                mn = min(mn, p[k].id);
            }
        }
    }
    long long res = line.size();
    sort(line.begin(), line.end(), cmp);
    //for(int i = 0; i < line.size(); i++)
    //    cout << line[i].x << " " << line[i].y << endl;
    //cout << line.size() << endl;
    res = res * (res - 1) / 2;
    line.push_back(point(1, INF, 0));
    int cnt = 1;
    for(int i = 1; i < line.size(); i++) {
        if (check(line[i], line[i - 1]))
            cnt++;
        else {
            res -= 1ll * cnt * (cnt - 1) / 2;
            cnt = 1;
        }
        //cout << cnt << endl;
    }
    cout << res;
    return 0;
}