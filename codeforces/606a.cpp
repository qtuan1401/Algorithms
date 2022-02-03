#include <bits/stdc++.h>

using namespace std;

int a[6];

int main() {
    for(int i = 0; i < 6; i++)
        cin >> a[i];
    int sum = 0;
    for(int i = 0; i < 3; i++)
        sum += (a[i] - a[i + 3]) / (1 + (a[i] > a[i + 3]));
    if (sum < 0)
        cout << "No";
    else
        cout << "Yes";
}