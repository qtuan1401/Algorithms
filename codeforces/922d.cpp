#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

struct node {
    int cntS, id;
    long long sum;
    node(const int &a = 0, const long long &b = 0, const int &c = 0) {
        cntS = a;
        sum = b;
        id = c;
    }
};

string s[MXN];
node a[MXN];
int n;

bool cmp(node a, node b) {
    int h1 = s[a.id].size() - a.cntS;
    int h2 = s[b.id].size() - b.cntS;
    //cout << h1 << " " << h2 << " " << a.sum << " " << b.sum << endl;
    return (1ll * h1 * b.cntS < 1ll * h2 * a.cntS);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    //long long res = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        int cntS = 0;
        long long res = 0;
        for(int j = 0; j < s[i].size(); j++)
            if (s[i][j] == 's')
                cntS++;
            else 
                res += cntS;
        a[i] = node(cntS, res, i);
    }

    //cout << cmp(a[0], a[1]);
    //return 0;
    sort(a, a + n, cmp);
    int cntS = 0;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        //cout << s[a[i].id] << endl;
        for(int j = 0; j < s[a[i].id].size(); j++)
            if (s[a[i].id][j] == 's')
                cntS++;
            else 
                res += cntS;
    }
    cout << res;
    return 0;
}