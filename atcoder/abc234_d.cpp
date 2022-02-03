#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    priority_queue < int, vector < int >, greater < int > > heap;
    for (int i = 0; i < k; i++)
        heap.push(a[i]);
    cout << heap.top() << '\n';
    for (int i = k; i < n; i++) {
        heap.push(a[i]);
        heap.pop();
        cout << heap.top() << '\n';
    }
    return 0;
}