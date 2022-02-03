#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > a(n);
    set < int > s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    vector < int > cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (s.find(a[i]) != s.end()) {
            s.erase(s.find(a[i]));
        }
        cnt[a[i]]++;
    }

    vector < int > appeared(n, n);
    for (int i = 0; i < n; i++)
        if (cnt[a[i]] == 1)
            appeared[a[i]] = i;

    int res = 0;
    set < int > :: iterator it = s.begin();
    for (int i = 0; i < n && it != s.end(); i++) {
        if (cnt[a[i]] > 1) {
            if (*it < a[i]) {
                cnt[a[i]]--;
                a[i] = *it++;
                res++;
            } else {
                if (appeared[a[i]] != n) {
                    cnt[a[i]]--;
                    a[i] = *it++;
                    res++;
                } else appeared[a[i]] = i;
            }
        }
    }
    
    cout << res << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << " ";
    return 0;
}