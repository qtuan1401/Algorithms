#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > II;

const int MAXN = 1e5 + 10;

int prime[MAXN], cnt[MAXN];
int n, k;
long long res = 0;

void eratos(int n) {
    for(int i = 2; i * i <= n; i++) 
        if (prime[i] == 0)
            for(int j = i * i; j <= n; j += i)
                if (prime[j] == 0)
                    prime[j] = i;
    for(int i = 2; i <= n; i++)
        if (prime[i] == 0)
            prime[i] = i;
}

void factorize(int x) {
    vector < II > vec;
    int r = 0;
    while (x != 1) {
        int cur = prime[x], c = 0;
 //       cout << cur << " " << x << endl;
        while (x % cur == 0) {
            c++;
            x /= cur;
        }
 //       cout << cur << " " << c << endl;
        vec.push_back(II(cur, c));
    }
//    cout << vec.size() << "*\n";
    long long t1 = 1, t2 = 1;
    for(int i = 0; i < vec.size(); i++) {
        //cout << vec[i].first << " " << vec[i].second << endl;
        int c = vec[i].second % k;
        if (c == 0)
            continue;
        for(int j = 1; j <= k - c; j++) {
            t2 *= vec[i].first;
            if (t2 > MAXN)
                t2 = 0;
        }
        for(int j = 1; j <= c; j++)
            t1 *= vec[i].first;    
    }
    res += cnt[t2];
    cnt[t1]++;
} 

int main() {
//    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    eratos(100000);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        factorize(x);
    }
    cout << res;
    //cout << cnt[1] << endl;
    return 0;
}