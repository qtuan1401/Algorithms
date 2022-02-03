#include <bits/stdc++.h>

using namespace std;

const double EPS = 5e-12;
const int MXN = 2e5 + 10;

double a[MXN];
int n;

double calc(double x) {
    double res = 0, sumMx = 0, sumMn = 0;
    //for(int i = 0; i < n; i++)
    //    cout << a[i] - x << " ";
    //cout << endl;
    for(int i = 0; i < n; i++) {
        sumMx = max(sumMx + a[i] - x, a[i] - x);
        sumMn = min(sumMn + a[i] - x, a[i] - x);
        res = max(res, max(sumMx, -sumMn));
        //cout << sumMx << " " << sumMn << endl;
    }
    //cout << resMx << " " << resMn << endl;
    return res;
}

double bs(double l, double r) {
    while (l + EPS < r) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        double f1 = calc(mid1);
        double f2 = calc(mid2);
        //cout << f1 << " " << f2 << " " << l << " " << r << " " << mid1 << " " << mid2 << endl;
        if (f1 < f2)
            r = mid2;
        else l = mid1;
    }
    //cout << "*" << l << endl;
    return calc(l);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    cout << fixed << setprecision(8);
    //cout << calc(3) << endl;
    //return 0;
    cout << bs(-2e4, 2e4);
    return 0;
}
