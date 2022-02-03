#include <bits/stdc++.h>
    
using namespace std;
    
typedef pair < long long, long long > II;
    
const long long md = 1e6 + 10;
    
long long seg[4 * md];
long long n, m, qq, x;
II cnt[md], q[md];
long long ans[md];
    
void update(long long k, long long l, long long r, long long pos) {
    if (l > pos || r < pos) return;
    if (l == r) {
        seg[k] = 1;
        return;
    }
    long long mid = (l + r) / 2;
    update(k * 2, l, mid, pos);
    update(k * 2 + 1, mid + 1, r, pos);
    seg[k] = seg[k * 2] + seg[k * 2 + 1];
}
    
long long get(long long k, long long l, long long r, long long cnt) {
    if (l == r) 
        return l;
    long long mid = (l + r) / 2;
    if (seg[k * 2] >= cnt) {
        return get(k * 2, l, mid, cnt);
    } else {
        return get(k * 2 + 1, mid + 1, r, cnt - seg[k * 2]);
    }
}
    
long long l = 1, done = 0;
void calc() {
    do {
        done += (l - 1) * (cnt[l].first - cnt[l - 1].first);
        update(1, 1, m, cnt[l].second);
        l++;
    } while (l <= m && cnt[l].first == cnt[l - 1].first);
}
    
int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> qq;
    for(long long i = 1; i <= m; i++) 
        cnt[i].second = i;
    
    for(long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        cnt[x].first++;
    }
    sort(cnt + 1, cnt + m + 1);
    for(long long i = 1; i <= qq; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }
    l = 1;
    calc();
    sort(q + 1, q + qq + 1);
    done = n;
    for(long long i = 1; i <= qq; i++) {
        while ((l - 1) * (cnt[l].first - cnt[l - 1].first) < q[i].first - done && l <= m)
            calc();
        long long pos = (q[i].first - done) % (l - 1);
        if (pos == 0) 
            pos = l - 1;
        ans[q[i].second] = get(1, 1, m, pos);
    }
    for(long long i = 1; i <= qq; i++) 
        cout << ans[i] << '\n';
    return 0;
}