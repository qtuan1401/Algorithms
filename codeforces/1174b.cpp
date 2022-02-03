#include <bits/stdc++.h>

using namespace std;


int a[100005];
int n, cnt0, cnt1;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], cnt0 += (a[i] % 2 == 0), cnt1 += (a[i] % 2 == 1);
    if (cnt0 && cnt1)
        sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}