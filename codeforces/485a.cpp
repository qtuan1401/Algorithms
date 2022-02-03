#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, m;
    cin >> a >> m;
    if (a % (m / (m & (-m))))
        cout << "No";
    else
        cout << "Yes";
}