#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

set < int > s;
int n;
int prime[MAXN];
vector < int > p;
vector < int > ans;

void eratos(int n) {
    for(int i = 2; i * i <= n; i++)
        if (prime[i] == 0)
            for(int j = i * i; j <= n; j += i)
                if (prime[j] == 0)
                    prime[j] = i;
    for(int i = 2; i <= n; i++) {
        if (prime[i] == 0) 
            prime[i] = i;
        ans.push_back(i / prime[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    
    eratos(n);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}