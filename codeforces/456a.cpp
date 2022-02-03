#include <bits/stdc++.h>

using namespace std;

int n;
pair < int , int > a[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int mn = a[n - 1].second;
    for(int i = n - 2; i >= 0; i--) {
        if (mn < a[i].second) {
            cout << "Happy Alex";
            return 0;
        }
        mn = min(mn, a[i].second);
    }
    cout << "Poor Alex";
    return 0;
}