#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int a[100005];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cnt = 1;
    for(int i = 2; i * i <= n; i++)
        if (a[i] == 0) {
            a[i] = cnt++;
            for(int j = i * i; j <= n; j += i)
                a[j] = a[i];
        }
    //for(int i = 2; i <= n; i++)
    //    cout << a[i] << " ";
    //cout << endl;
    for(int i = 2; i <= n; i++) {
        if (a[i] == 0)
            a[i] = cnt++;
        cout << a[i] <<" ";
    }
    return 0;
}