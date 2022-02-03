#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int a[N];
int n, m;

int bs(int l, int r) {
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << mid << endl;
        int pre = 0; 
        bool ok = true;
        for(int i = 0; i < n; i++) {
            int l = a[i], r = a[i] + mid;
            if ((l <= pre && pre <= r) || (l <= pre + m && pre + m <= r))
                continue;
            if (l < pre) {
                ok = false;
                break;
            } else 
                pre = l;
        }
        if (!ok) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << bs(0, m);
    return 0;
}