#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    vector < int > v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() == n) 
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
    return 0;
}