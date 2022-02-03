#include <bits/stdc++.h>

using namespace std;

typedef complex < double > point;

const int MXN = 1e5 + 10;

point p[MXN];

inline double dot(point a, point b) {
    return real(conj(a) * b);
}

inline double cross(point a, point b) {
    return imag(conj(a) * b);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n >> x >> y;
    point o(x, y);

    double mn = 1e9, mx = 0;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }

    for(int i = 0; i < n; i++) {
        point a = p[i], b = p[(i + 1) % n];

        if (dot(b - a, o - a) >= 0 && dot(a - b, o - b) >= 0)
            mn = min(mn, abs(cross(o - a, b - a)) / abs(b - a));
        mn = min(mn, abs(a - o));
        mx = max(mx, abs(a - o));
    }

    cout << fixed << setprecision(15);
    cout << (mx * mx - mn * mn) * acos(-1);

    return 0;
}
