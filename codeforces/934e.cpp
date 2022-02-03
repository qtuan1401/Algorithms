#include <bits/stdc++.h>

const double EPS = 1e-9;

using namespace std;

int n, cnt;
int x[5], y[5], r[5], c[5][5];

int check(int a, int b) {
    int dst = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
    int dst1 = (r[a] - r[b]) * (r[a] - r[b]);
    int dst2 = (r[a] + r[b]) * (r[a] + r[b]);

    if (dst < dst1) return -2;
    else if (dst == dst1) return -1;
    else if (dst < dst2) return 0;
    else if (dst == dst2) return 1;
    return 2;
}

void getIntersections(int a, int b, double ix[2], double iy[2]) {
    double angle = atan2(y[b] - y[a], x[b] - x[a]);
    double dst = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
    double delta = acos((dst * dst + r[a] * r[a] - r[b] * r[b]) / (2.0 * r[a] * dst));
    ix[0] = x[a] + r[a] * cos(angle + delta);
    iy[0] = y[a] + r[a] * sin(angle + delta);
    ix[1] = x[a] + r[a] * cos(angle - delta);
    iy[1] = y[a] + r[a] * sin(angle - delta);
}

bool onCircle(int a, double x0, double y0) {
    return fabs((x[a] - x0) * (x[a] - x0) + (y[a] - y0) * (y[a] - y0) - r[a] * r[a]) <= EPS;
}

void init() {
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) 
            if (c[i][j] >= -1 && c[i][j] <= +1) {
                int k = 3 - i - j;
                double ix[2], iy[2];
                getIntersections(i, j, ix, iy);
                cnt += onCircle(k, ix[0], iy[0]);
                cnt += (onCircle(k, ix[1], iy[1]) && c[i][j] == 0);
                break;
            }
        if (cnt != 0) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            c[i][j] = c[j][i] = check(i, j);

    if (n == 1) {
        cout << 2;
    } else if (n == 2) {
        cout << (c[0][1] == 0 ? "4" : "3");
    } else if (n == 3) {
        init();
        //cout << cnt << endl;
        int x[3] = { c[0][1], c[0][2], c[1][2] };
        sort(x, x + 3);
        if (x[0] == -2) {
            cout << 4 + (x[1] == 0) + (x[2] == 0);
        } else if (x[0] == -1) {
            if (x[1] == -1) {
                cout << (x[2] == -1 ? 4 : (6 - x[2]));
            } else {
                int cases = x[1] * 10 + x[2];
                if (cases == 0)
                    cout << 7 - cnt;
                else if (cases == 1)
                    cout << 6;
                else if (cases == 2)
                    cout << 5;
                else 
                    cout << 4;
            }
        } else if (x[0] >= 1) {
            cout << (x[0] == 1 && x[2] == 1 ? "5" : "4");
        } else {  
            int cases = x[1] * 10 + x[2];
            if (cases == 0)
                cout << 8 - cnt;
            else if (cases == 1)
                cout << 7 - cnt;
            else if (cases == 2 || cases == 11)
                cout << 6;
            else 
                cout << 5;
        }
    } 

    return 0;
}