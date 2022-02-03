#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
    point(const int &x = 0, const int &y = 0) : x(x), y(y) {}
    void input() {
        cin >> x >> y;
    }
};

const int md = 5e3 + 10;

point a[md];
int n;

bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

int main() {
//    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        a[i].input();
    a[n + 1] = a[1];
    //-cout << n << endl;
    //for(int i = 1; i <= n; i++)
        //cout << a[i].x <<" " << a[i].y << endl;
    int m;
    cin >> m;
    //cout << m << endl;
    while (m--) {
        long long x, y;
        cin >> x >> y;
        bool ok = false;
        point b = point(x, y);
        for(int i = 1; i <= n; i++) {
            if (ccw(a[i], a[i + 1], b)) {
                ok = true;
                break;
            }
        }
        cout << ((ok) ? "NO\n" : "YES\n");
    }
    return 0;
}
