#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n, mx = 0;
    cin >> n;
    vector < int > ans, a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l > 0 && a[l - 1] % a[i] == 0)
            l--;
        while (r < n - 1 && a[r + 1] % a[i] == 0)
            r++;
        //cout << l << " " << r << " " << mx << " " << a[i] << endl;
        i = r;
        r -= l;
        //cout << l << " " << r << " " << mx << " " << i << endl;
        if (r > mx) {
            mx = r;
            ans.clear();
        } 
        if (r == mx) 
            ans.push_back(l + 1);
    }
    cout << ans.size() << " " << mx << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}