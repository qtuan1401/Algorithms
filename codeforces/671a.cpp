#include<bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
};

inline double dst(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    point a, b, t;
    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
	cin >> n;
	double sum = 0;
	double dstA = 1e15, dstB = 1e15, dstAB = 1e15;
	for(int i = 0; i < n; i++) {
        point d;
        cin >> d.x >> d.y;
		sum += 2 * dst(d, t);
        double dst1 = dst(a, d) - dst(d, t);
        double dst2 = dst(b, d) - dst(d, t);
        dstAB = min(dstAB, min(dstA + dst2, dstB + dst1));
		dstA = min(dstA, dst1);
		dstB = min(dstB, dst2);
	}
    cout << fixed << setprecision(15);
    cout << sum + min(dstAB, min(dstA, dstB));
    return 0;
}