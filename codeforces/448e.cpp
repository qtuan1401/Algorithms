#include <bits/stdc++.h>

using namespace std;

int len = 1e5;
vector < long long > divisor;
long long n, k;

void dfs(int p, int depth) {
    if (!len)
        return ;
    if (p == 0 || depth == k) {
        len--;
        cout << divisor[p] << " ";
        return ;
    }
    for(int i = 0; i <= p; i++) {
        if (divisor[p] % divisor[i] == 0)
            dfs(i, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; 1ll * i * i < n; i++) {
        if (n % i == 0)
            divisor.push_back(i);
    } 
    for(int i = sqrt(n); i >= 1; i--)
        if (n % i == 0)
            divisor.push_back(n / i);
    
    dfs((int)divisor.size() - 1, 0);
    return 0;
}