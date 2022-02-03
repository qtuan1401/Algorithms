#include <bits/stdc++.h>

#define fori(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (b); i >= (a); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rev(i, a, b) for(int i = (b); i > (a); i--)
#define Memset(a, value) memset(a, value, sizeof(a))
#define forv(i, a) for(int i = 0; i < a.size(); i++)
#define max_heap(type) priority_queue< type >
#define min_heap(type) priority_queue< type, vector < type >, greater< type > >

using namespace std;
typedef pair< int, int> ii;
typedef pair< int, ii> iii;
typedef long long ll;
typedef unsigned long long ull;

const int md = 6e3 + 10;
const int oo = 1e9 + 10;

int a[md][md];
int n, m;
ll res;
ll f[md][md];

inline bool check(int i, int j, int type) {
    if (type)
        return ((i & 1) ? (j % 2 == 0) : (j % 2 == 1));
    return ((i & 1) ? (j % 2 == 1) : (j % 2 == 0));
}

int main() {
//    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
//    cout << n << " " << m << endl;
    int d = 0;
    ford(i, 1, n) {
        fori(j, 1 + d, n * 2 - 1 - d)
            a[i][j] = 1;
        // fori(j, 1 + d, n * 2 - 1 - d)
        //     cout << j <<" ";
        // cout << endl;
        d++;
    }
    // fori(i, 1, n) {
    //     fori(j, 1, 2 * n - 1)
    //         cout << a[i][j] <<" ";
    //     cout << endl;
    // }
    fori(i, 1, m) {
        int x, y, z;
        cin >> x >> y >> z;
        int pos = 0;
        pos = z + (y - 1) * 2;
        //cout << pos << endl;
        if (n & 1)
            pos += (z & 1) ? ((x + y) % 2 == 1) : ((x + y) % 2 == 0);
        else
            pos += (z & 1) ? ((x + y) % 2 == 0) : ((x + y) % 2 == 1);
        a[n - z + 1][pos] = 0;
        //cout << x <<" " << y << " " << z << endl;
        //if (x == 3 && y == 2 && z == 1)
        //    cout << n - z + 1 << " " << pos << endl;
    //    if (n - z + 1 == 7 && pos == 1)
    //        cout << x <<" " << y << " " << z << endl;
    }
//    cout << endl;
    // fori(i, 1, n) {
    //     fori(j, 1, 2 * n - 1)
    //         cout << a[i][j] <<" ";
    //     cout << endl;
    // }
    m = n * 2 - 1;
    // fori(i, 1, n) {
    //     fori(j, 1, m)
    //         cout << a[i][j] <<" ";
    //     cout << endl;
    // }
    //cout << a[2][7] << endl;
    if (n & 1) {
        fori(i, 1, n)
            fori(j, 1, m)
                if (a[i][j] && check(i, j, 1)) {
        //            cout << i <<" " << j << endl;
                    f[i][j] = 1;
                    if (a[i - 1][j])
                        f[i][j] = min(f[i - 1][j - 1], f[i - 1][j + 1]) + 1;
                    res += f[i][j];
                }
        //cout << res << endl;
        // fori(i, 1, n) {
        //     fori(j, 1, m)
        //         cout << f[i][j] <<" ";
        //     cout << endl;
        // }
        ford(i, 1, n)
            fori(j, 1, m)
                if (a[i][j] && check(i, j, 0)) {
                    f[i][j] = 1;
                    if (a[i + 1][j])
                        f[i][j] = min(f[i + 1][j - 1], f[i + 1][j + 1]) + 1;
                    res += f[i][j];
                }
    } else {
        fori(i, 1, n)
            fori(j, 1, m)
                if (a[i][j] && check(i, j, 0)) {
        //            cout << i <<" " << j << endl;
                    f[i][j] = 1;
                    if (a[i - 1][j])
                        f[i][j] = min(f[i - 1][j - 1], f[i - 1][j + 1]) + 1;
                    res += f[i][j];
                }
        //cout << res << endl;
        // fori(i, 1, n) {
        //     fori(j, 1, m)
        //         cout << f[i][j] <<" ";
        //     cout << endl;
        // }
        ford(i, 1, n)
            fori(j, 1, m)
                if (a[i][j] && check(i, j, 1)) {
                    f[i][j] = 1;
                    if (a[i + 1][j])
                        f[i][j] = min(f[i + 1][j - 1], f[i + 1][j + 1]) + 1;
                    res += f[i][j];
                }
    }
    cout << res;
    return 0;
}
