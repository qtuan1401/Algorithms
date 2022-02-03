#include <bits/stdc++.h>

using namespace std;

const int md = 55;

string s;
int a[md][md];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)  {
        cin >> s;
        for(int j = 0; j < n; j++)
            a[i][j + 1] = (s[j] == '.');
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            if (a[i][j] == 1 && a[i - 1][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i][j - 1] == 1) 
                a[i][j] = a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = 0;
            
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                cout << "NO";
                return 0;
            }
    }
    cout << "YES";
    return 0;
}