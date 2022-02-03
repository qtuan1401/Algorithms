#include <bits/stdc++.h>
 
using namespace std;
 
typedef long double ld;
 
struct point {
    ld x, y;
    point(const ld& x = 0.0, const ld& y = 0.0) : x(x), y(y) {}
    void input() {
        cin >> x >> y;
    }
};
 
struct line {
    ld a, b, c;
    line(const ld& a = 0.0, const ld& b = 0.0, const ld& c = 0.0) : a(a), b(b), c(c) {};
};
 
const int md = 1e3 + 10;
const ld eps = 1e-9;
 
point a[md], b[md];
int t, n, m;
 
bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y -  b.y) < 0;
}
 
line Line(point a, point b) {
    line c;
    c.a = b.y - a.y;
    c.b = a.x - b.x;
    c.c = c.a * a.x + c.b * a.y;
    return c;
}
 
ld equal(ld a, ld b) {
    return (fabs(a - b) < eps);
}
 
ld dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
 
bool onSegment(point a, point b, point c) {
    point p1 = point(c.x - a.x, c.y - a.y);
    point p2 = point(c.x - b.x, c.y - b.y);
    //cout << p1.x <<" " << p1.y <<" " << p2.x <<" " << p2.y << endl;
    //cout << dot(p1, p2) << endl;
//    cout << p1.x * p2.y <<" " << p2.x * p1.y << endl;
    return (equal(p1.x * p2.y, p2.x * p1.y) && (dot(p1, p2) <= 0));
}
 
bool intersectline(point a, point b, point c, point d) {
    line l1 = Line(a, b);
    line l2 = Line(c, d);
//    cout << l1.a <<" " << l1.b <<" " << l1.c << endl;
//    cout << l2.a <<" " << l2.b <<" " << l2.c << endl;
    ld determiant = l1.a * l2.b - l2. a * l1.b;
    if (determiant == 0)
        return false;
    ld x = (l2.b * l1.c - l2.c * l1.b) / determiant;
    ld y = (l1.a * l2.c - l1.c * l2.a) / determiant;
    point p = point(x, y);
//    cout << x <<" " << y << endl;
//    if (equal(x, a.x) && equal(y, a.y)) return false;
//    if (equal(x, b.x) && equal(y, b.y)) return false;
//    if (equal(x, c.x) && equal(y, c.y)) return false;
//    if (equal(x, d.x) && equal(y, d.y)) return false;
    //cout << "z";
//    cout << "(" << a.x <<" " << a.y <<") (" << b.x <<" " << b.y << ") (" <<p.x <<" " << p.y << ")\n";
//    cout << onSegment(a, b, p) << endl;
//    return 0;
    return (onSegment(a, b, p) && onSegment(c, d, p));
}
 
bool cut(point b1, point b2) {
    bool ok = false;
    for(int i = 1; i <= n; i++)
        if (intersectline(b1, b2, a[i], a[i + 1])) {
            ok = true;
            break;
        }
    return ok;
}
 
bool inside() {
 
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 1; j <= m; j++)
            if (ccw(b[j], b[j + 1], a[i])) {
                ok = false;
                break;
            }
        if (ok)
            return true;
    }
    for(int i = 1; i <= m; i++) {
        bool ok1 = true;
        for(int j = 1; j <= n; j++)
            if (ccw(a[j], a[j + 1], b[i])) {
                ok1 = false;
                break;
            }
        if (ok1)
            return true;
    }
    return false;
}
 
int main() {
    //freopen("6.in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    //cout << intersectline(point(-6, 3), point(-10, 6), point(-3, 5), point(-6.4, 3.3));
    //return 0;
    while (t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            a[i].input();
        a[n + 1] = a[1];
        cin >> m;
        for(int i = 1; i <= m; i++)
            b[i].input();
        b[m + 1] = b[1];
        bool ok = false;
        if (inside()) {
            cout << "YES\n";
            continue;
        }
        for(int i = 1; i <= m; i++) {
            ok |= cut(b[i], b[i + 1]);
        }
        cout << ((ok) ? "YES\n" : "NO\n");
    }
    return 0;
}