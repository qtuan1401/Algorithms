#include <bits/stdc++.h>

using namespace std;

map < long long , long long > mp;

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    for( ; k > 0 && n % k == --k; );
    if (k > 0)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}