#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e5 + 10;

int prime[MXN], cnt[MXN];

void eratos(int n) {
    for(int i = 2; i <= n; i++)
        if (prime[i] == 0)
            for(int j = i; j <= n; j += i)
                prime[j] = i;
} 

vector < int > factorize(int x) {
    vector < int > fact;
    while (x > 1) {
        fact.push_back(prime[x]);
        int num = prime[x];
        while (x % num == 0)
            x /= num;
    }
    return fact;
}

inline int getBit(int x, int i) {
    return ((x >> i) & 1);
}

void update(vector < int > fact, int val) {
    int len = fact.size();
    //cout << len << endl;
    //for(int i = 0; i < fact.size(); i++)
    //    cout << fact[i] << " ";
    //cout << endl;
    for(int i = 0; i < (1 << len); i++) {
        int cur = 1;
        for(int j = 0; j < len; j++)
            if (getBit(i, j))
                cur *= fact[j];
        if (cur != 1)
            cnt[cur] += val;
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector < int > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    eratos(5e5);
    set < int > shelf;
    long long res = 0;
    while (q--) {
        int x;
        cin >> x;
        x--;
        //cout << "*" << x << " " << a[x] << endl;
        vector < int > fact = factorize(a[x]);
        int len = fact.size();
        bool isPop = (shelf.find(x) != shelf.end());
        //cout << x << " " << isPop << endl;
        if (isPop)
            update(fact, -1);
        long long sum = 0;
        //cout << x << " " << a[x] << " " << len << endl;
        for(int i = 0; i < (1 << len); i++) {
            int cntBit = 0, cur = 1;
            for(int j = 0; j < len; j++)
                if (getBit(i, j)) {
                    cur *= fact[j];
                    cntBit++;
                }
            //cout << cur << " " << cnt[cur] << endl;
            if (cntBit & 1)
                sum += cnt[cur];
            else 
                sum -= cnt[cur];
        }
        if (!isPop)
            update(fact, 1);
        //cout << sum << " " << shelf.size() << endl;
        if (isPop) {
            shelf.erase(shelf.find(x));
            res -= ((int)shelf.size() - sum);
        } else {
            //cout << res << " " << shelf.size() - sum << endl;
            res += ((int)shelf.size() - sum);
            shelf.insert(x);
        }
        cout << res << '\n';
    }
    return 0;
}