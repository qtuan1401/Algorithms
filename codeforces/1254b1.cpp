#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];
vector < int > vec, divList;
int n, sum;
long long ans;

int main() {
    //freopen("test.in", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			vec.push_back(i);
			sum++;
		}
	}
	if (sum <= 1) {
		cout << "-1\n";
		return 0;
	}
	int num = 0;
	for(num = 2; num <= sum; num++)
		if (sum % num == 0)
			divList.push_back(num);
    ans = 1e18;
    for(int j = 0; j < divList.size(); j++) {
        int num = divList[j];
        long long res = 0;
        for(int i = 0; i < vec.size(); i += num) {
            int l = i, r = i + num - 1;
            int mid = (r - l + 2) / 2;
            //cout << mid << " " << l << " " << r << endl;
            for(int j = l; j <= r; j++)
                res += (abs(vec[j] - vec[i + mid - 1]));
        }
        ans = min(ans, res);
    }
	cout << ans;
	return 0;
}