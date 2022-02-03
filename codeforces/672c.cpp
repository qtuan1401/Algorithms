#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int md =  1e5 + 10;

ll ax, ay, bx, by, ox, oy;

double calc(ll ax, ll ay, ll bx, ll by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

pair < double, double > d[md];
double res = 0;
int n;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> ax >> ay >> bx >> by >> ox >> oy;
    cin >> n;
    double ma = 1e18, mb = 1e18, mab = 1e18;
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        double dist = calc(x, y, ox, oy);
        double da = calc(ax, ay, x, y) - dist;
        double db = calc(bx, by, x, y) - dist;
        res += 2 * dist;
        mab = min(mab, min(ma + db, mb + da));
        ma = min(ma, da); mb = min(mb, db);
    }
    cout << fixed << setprecision(10);
    cout << res + min(mab, min(ma, mb)); 
    return 0;
}