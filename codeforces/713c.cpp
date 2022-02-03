#include <bits/stdc++.h>

using namespace std;

int a[3005];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long res = 0;
    priority_queue < int > heap;
    heap.push(a[0]);
    for (int i = 1; i < n; i++) {
        a[i] -= i;
        heap.push(a[i]);
        if (heap.top() > a[i]) {
            res += heap.top() - a[i];
            heap.pop();
            heap.push(a[i]);
        }
    }
    cout << res;
    return 0;
}