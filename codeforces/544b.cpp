#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;
bool sand[105][105];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    if (k == 0) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << "S";
            cout << '\n';
        }
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                sand[i][j] = 1;
                cnt++;
                if (cnt == k) {
                    cout << "YES\n";
                    for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++)
                            cout << (sand[i][j] == 1 ? "L" : "S");
                        cout << '\n';
                    }
                    return 0;
                }
            }
        }
    cout << "NO";
    return 0; 
}