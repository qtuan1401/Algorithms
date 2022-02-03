#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e5 + 10;

long long n;
long long sum[MXN];
vector < long long > a;
inline double calc(int x) {
	return (sum[x]+a.back()) * 1.0 / (x * 1.0 + 1.0);
}

double ts(int l, int r) {
    double ans=0;
    while(l <= r) {
        int mid1 = (r - l) / 3 + l;
        int mid2 = r -(r - l) / 3;
        double res1 = calc(mid1), res2 = calc(mid2);
        if(res1 > res2)	{
            l = mid1 + 1;
            ans = max(ans, (double)a.back() - res1);
        } else {
            r = mid2 - 1;
            ans = max(ans, (double)a.back() - res2);
        }	
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    cout << fixed << setprecision(15);
	while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            long long x;
            cin >> x;
            a.push_back(x);
            sum[a.size()] = sum[a.size() - 1] + x;
        } else {
			cout << ts(1, a.size() - 1) << '\n';
		}
	}
}