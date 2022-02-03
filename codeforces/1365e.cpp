#include <bits/stdc++.h>

using namespace std;

int n;
vector < int > a;
long long res = 0;

inline int getBit(long long x, int i) {
    return ((x >> i) & 1);
}

void solve(int bit) {
    //cout << bit << endl;
    vector < int > temp;
    for(int i = 0; i < a.size(); i++)
        if (getBit(a[i], bit)) 
            temp.push_back(a[i]);
    //cout << res << endl;
    if (temp.size()) {
        //for(int i = 0; i < temp.size(); i++)
        //    cout << temp[i] << " * ";
        //cout << endl;
        //cout << res << " " << bit << endl;
        res += (1ll << bit);
        //cout << res << " " << bit << endl;
        //for(int i = 0; i < a.size(); i++)
        //    cout << a[i] << " ";
        //cout << endl;
        //for(int i = 0; i < temp.size(); i++)
        //    cout << temp[i] << " ";
        //cout << endl;
        a.clear();
        for(int i = 0; i < temp.size(); i++)
            a.push_back(temp[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    //for(int i = 0; i < a.size(); i++)
    //    cout << a[i] << " * ";
    //cout << res << endl;
    for(int i = 60; i >= 0; i--)
        solve(i);
    cout << res;
    return 0;
}