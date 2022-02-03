#include <bits/stdc++.h>

using namespace std;

const int cnt[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
    int n;
    cin >> n;
    cout << cnt[n / 10] * cnt[n % 10];
}