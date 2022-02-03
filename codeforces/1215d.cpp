#include <bits/stdc++.h>

using namespace std;

int sum, cnt, n;
string s;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    s = "#" + s;
    for(int i = 1; i <= n / 2; i++)
        if (s[i] == '?') 
            cnt++;
        else sum += s[i] - '0';
    for(int i = n / 2 + 1; i <= n; i++)
        if (s[i] == '?')
            cnt--;
        else sum -= s[i] - '0';
    //cout << sum << " " << cnt << endl;
    if (sum == 0 && cnt == 0)
        cout << "Bicarp";
    else if (sum == 0)
        cout << "Monocarp";
    else if ((sum < 0 && cnt < 0) || (sum > 0 && cnt > 0))
        cout << "Monocarp";
    else {
        //cout << sum << " " << cnt  << endl;
        sum += cnt / 2 * 9;
        if (sum == 0)
            cout << "Bicarp";
        else cout << "Monocarp";
    }  
    return 0;
}
//