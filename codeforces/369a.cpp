#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            if (m > 0)
                m--;
            else
                res++;
        } else {
            if (k > 0)
                k--;
            else {
                if (m > 0)
                    m--;
                else
                    res++;
            }
        }
    }
    cout << res;
	return 0;
}