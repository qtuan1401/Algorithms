#include <bits/stdc++.h>

using namespace std;

int n, x;
int ss[1000000];
vector < int > v;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    ss[0] = ss[x] = 1;
    for(int i = 1; i < (1 << n); i++) {
        if (ss[i] == 1) continue;
        v.push_back(i);
        ss[i] = ss[i ^ x] = 1;
    }
    //return 0;
    cout << v.size() << '\n';
    if (v.size() == 0)
        return 0;
    cout << v[0] << " ";
    for(int i = 1; i < v.size(); i++)
        cout << (v[i] ^ v[i - 1]) << " ";
    return 0;   
}