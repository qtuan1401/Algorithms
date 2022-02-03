#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

long long cnt[MXN];
int a[MXN];
int n;

int convert(int x) {
    if (x < 0)
        x += n;
    if (x == 0)
        x = n;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int s, f;
    cin >> s >> f;
    for(int i = 0; i < n; i++) {
        int ns = convert(s - i);
        int nf = convert(f - i);
        cnt[ns] += a[i];
        cnt[nf] -= a[i];
        if (ns > nf)
            cnt[1] += a[i];
        //cout << ns << " " << nf << endl;
    }
    for(int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    long long mx = 0;
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        if (mx < cnt[i]) {
            mx = cnt[i];
            pos = i;
        }
        //cout << cnt[i] << " ";
    }
    cout << convert(pos);
    return 0;
}