#include <bits/stdc++.h>

using namespace std;

#define fori(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, b, a) for(int i = (b); i >= (a); i++)

struct point {
    double x, y;
    bool input() {
        scanf("%lf %lf", &x, &y);
    }
};

const int md = 1e5 + 10;

point a[md];
double ans = 1e15;
int n;

bool cmpX(point a, point b) {
    return a.x < b.x;
}

bool cmpY(point a, point b) {
    return a.y < b.y;
}

void check(point a, point b) {
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    ans = min(ans, dist);
}

void solve(int l, int r) {
    //cout << l << " " << r << endl;
    if (l >= r)
        return ;
    if (l + 1 == r) {
        check(a[l], a[r]);
        if (a[r].y < a[l].y)
            swap(a[r], a[l]);
        return ;
    }
//    cout << "Z" << endl;
    int mid = (l + r) >> 1;
    double c = a[mid].x;
    //cout << c << endl;
    solve(l, mid);
    solve(mid + 1, r);
    point tmp[md];
    merge(a + l, a + mid + 1, a + mid + 1, a + r + 1, tmp + 1, cmpY);
    copy(tmp + 1, tmp + r - l + 2, a + l);
//    fori(i, 1, r - l + 1)
//        cout << tmp[i].x << " ";
//    cout << endl;
    int rr = 0;
    fori(i, l, r)
        if (abs(a[i].x - c) < ans) {
            for(int j = rr; j >= 1 && tmp[j].y > a[i].y - ans; j--)
                check(a[i], tmp[j]);
            tmp[++rr] = a[i];
        }
}

int main() {
//    freopen("test.in", "r", stdin);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> n;
    scanf("%d", &n);
    //cout << n << endl;
    fori(i, 1, n)
        a[i].input();
    sort(a + 1, a + 1 + n, cmpX);
    solve(1, n);
    //cout << fixed << setprecision(3);
    //cout << ans;
    printf("%.3lf", ans);
    return 0;
}
