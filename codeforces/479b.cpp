#include <bits/stdc++.h>

using namespace std;

const int MXN = 105;

int n, k, cnt;
int a[105], l[1005], r[1005]; 

int * findMax() {
    return max_element(a, a + n);
}

int * findMin() {
    return min_element(a, a + n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    //cout << findMax() - findMin() << endl;
    while(*findMax() - *findMin() > 1 && cnt < k) {
        l[cnt] = findMax() - a;
        r[cnt] = findMin() - a;
        a[l[cnt]]--; a[r[cnt]]++;
        cnt++;
    }
    cout << *findMax() - *findMin() << " " << cnt << '\n';
    for (int i = 0; i < cnt; i++) 
        cout << l[i] + 1 << " " << r[i] + 1 << '\n';
    return 0;
}