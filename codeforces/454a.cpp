#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if (abs(i - (n - 1) / 2) + abs(j - (n - 1) / 2) <= (n - 1) / 2)
                cout << "D";
            else
                cout << "*";
        cout << '\n';
    }
    return 0;
}
