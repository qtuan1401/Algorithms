// codeforces 961d

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct point {
    LL x, y;
    point(const LL& x = 0.0, const LL& y = 0.0) : x(x), y(y) {}
    void input() {
        cin >> x >> y;
    }

    bool operator < (const point & p) const {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }

    bool operator != (const point & p) const {
        return (x != p.x || y != p.y);
    }
};

struct line {
    LL a, b, c;
    line(const LL& a = 0.0, const LL& b = 0.0, const LL& c = 0.0) : a(a), b(b), c(c) {};
};

line createLine(point a, point b) {
    line c;
    c.a = b.y - a.y;
    c.b = a.x - b.x;
    c.c = c.a * a.x + c.b * a.y;
    return c;
}

inline bool ccw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
inline bool cw(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
vector < point > convex_hull(vector < point > v) {
    sort(v.begin(), v.end()); 
    point p1 = v[0];
    point p2 = v.back();
    vector< point > down, up;
    up.push_back(p1);
    down.push_back(p1);
    for(long long i = 1; i < v.size(); i++) {
        if (i == v.size() - 1 || cw(p1, v[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || ccw(p1, v[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    vector < point > ans;
    for(int i = 0; i < up.size(); i++) 
        ans.push_back(up[i]);
    for(int i = down.size() - 2; i > 0; i--)
        ans.push_back(down[i]);
    return ans;
}

int n;
vector < point > a;

bool onLine(line l, point p) {
    return (l.a * p.x + l.b * p.y == l.c);
}

bool check3(point x, point y, point z) {
    line l = createLine(x, y);
    int cnt = 0;
    vector < point > remain;
    for(int i = 0; i < n; i++) {
        if (a[i] != x && a[i] != y && a[i] != z) {
            if (!onLine(l, a[i]))
                remain.push_back(a[i]);
        }
    }
    if (remain.empty())
        return true;
    l = createLine(z, remain[0]);
    for(int i = 0; i < remain.size(); i++)
        if (!onLine(l, remain[i]))
            return false;
    return true;
}

bool check4(point p1, point p2, point p3, point p4) {
    line l1 = createLine(p1, p2);
    line l2 = createLine(p3, p4);
    for(int i = 0; i < n; i++) {
        if (a[i] != p1 && a[i] != p2 && a[i] != p3 && a[i] != p4) {
            if (!onLine(l1, a[i]) && !onLine(l2, a[i]))
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        a[i].input();

    vector < point > h = convex_hull(a);

    if (h.size() > 4) {
        cout << "NO";
        return 0;
    } else {
        if (h.size() == 1 || h.size() == 2) {
            cout << "YES";
        } else if (h.size() == 3) {
            if (check3(h[0], h[1], h[2]) || check3(h[1], h[2], h[0]) || check3(h[0], h[2], h[1])) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            if (check4(h[0], h[1], h[2], h[3]) || check4(h[0], h[2], h[1], h[3]) || check4(h[0], h[3], h[1], h[2]))
                cout << "YES";
            else cout << "NO";
        }
    }
    return 0;
}