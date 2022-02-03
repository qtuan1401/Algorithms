#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

int s,n,i,k,j;
II d[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    vector < II > a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int sum = 0, pos = n;
    for(int i = 0; i < n; i++) {
        sum += a[i].first;
        if (sum > s) {
            pos = i;
            break;
        }
    }
    cout << pos << '\n';
    for(int i = 0; i < pos; i++)
        cout << a[i].second + 1 << " ";
    return 0;
}