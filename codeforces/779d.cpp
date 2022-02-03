#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

string s, t;
int n;
int a[MXN];
bool marked[MXN];

bool check(int lim) {
    for(int i = 0; i < n; i++)
        marked[i] = 0;
    for(int i = 0; i < lim; i++)
        marked[a[i] - 1] = 1;
    string temp = "";

    for(int i = 0; i < n; i++)
        if (!marked[i])
            temp += s[i];
    //cout << lim << " "  << temp << " " << t << endl;
    for(int i = 0, j = 0; i < temp.size(); i++) {
    //    cout << temp[i] << " " << t[j] << " " << i << " " << j << endl;
        if (temp[i] == t[j]) {
            j++;
            if (j == t.size())
                return true;
        }
        //cout << j << " ";
    }
    return false;
}

int bs(int l, int r) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << mid << endl;
        if (check(mid)) {
            pos = mid;
            l = mid + 1;
        } else 
            r = mid - 1;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    //cout << s << endl;
    cin >> t;
    n = s.size();
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << bs(0, n);
    return 0;
}