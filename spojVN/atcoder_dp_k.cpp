#include <bits/stdc++.h>

using namespace std;

int n, k;
vector < int > a, marked, memo;

bool solve(int k) {
    if (k < 0) return true;
    if (marked[k]) return memo[k];

    marked[k] = true;
    bool res = false;
    for (int i = 0; i < n; i++)
        res |= !solve(k - a[i]);
    
    return memo[k] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    a.resize(n); marked.resize(k + 1), memo.resize(k + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << (solve(k) == true ? "First" : "Second");
    return 0;
}