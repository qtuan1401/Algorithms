#include <bits/stdc++.h>

using namespace std;

int a, b, s;

int main() {
    cin >> a >> b >> s;
    int sum = abs(a) + abs(b);
    if (sum % 2 == s % 2 && sum <= s)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}