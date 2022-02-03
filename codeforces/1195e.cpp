#include <bits/stdc++.h>

using namespace std;

const int md = 3e3 + 5;

int n, m, a, b;
long long x, y, z, res = 0;
long long h[md][md], g[md * md], val[md], mn[md][md];
deque < long long > dmin;

void push(int i) {
	while (!dmin.empty() && val[dmin.back()] > val[i])
		dmin.pop_back();
	dmin.push_back(i);
}
 
void pop(int i) {
	while (!dmin.empty() && dmin.front() <= i)
		dmin.pop_front();
}

void reset() {
    while (!dmin.empty())
        dmin.pop_front();
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> a >> b;
    cin >> g[0] >> x >> y >> z;
    for(int i = 1; i <= m * n; i++)
        g[i] = (g[i - 1] * x + y) % z;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            h[i][j] = g[(i - 1) * m + j - 1];
    for(int j = 1; j <= m; j++) {
        reset();
        for(int i = 1; i <= n; i++)
            val[i] = h[i][j];
        for(int i = 1; i <= a; i++)
            push(i);
        mn[a][j] = val[dmin.front()];
        for(int i = a + 1; i <= n; i++) {
            pop(i - a);
            push(i);
            mn[i][j] = val[dmin.front()];
        }
    }
    for(int i = a; i <= n; i++) {
        reset();
        for(int j = 1; j <= m; j++)
            val[j] = mn[i][j];
        for(int j = 1; j <= b; j++)
            push(j);
        res += val[dmin.front()];
        for(int j = b + 1; j <= m; j++) {
            pop(j - b);
            push(j);
            res += val[dmin.front()];
        }
    }
    cout << res;
    return 0;
}