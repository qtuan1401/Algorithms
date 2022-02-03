#include <bits/stdc++.h>

using namespace std;

int n, num;
int a[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i += 4) {
        for(int j = 1; j <= n; j += 4)
            for(int ii = 0; ii < 4; ii++)
                for(int jj = 0; jj < 4; jj++)
                   a[i + ii][j + jj] = num++;
        
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}