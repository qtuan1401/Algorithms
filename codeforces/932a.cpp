#include <bits/stdc++.h>

using namespace std;

string a;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a;
    string b = a;
    reverse(b.begin(), b.end());
    cout << a + b;
    return 0;
}