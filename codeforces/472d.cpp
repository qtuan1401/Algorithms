#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e3 + 10;

int a[MXN][MXN];
int n;

int main() {
    //ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        if (a[i][i] > 0)
            ok = false;
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i] || (a[i][j] == 0 && i != j))
                ok = false;
    for(int i = 0; i < n; i++) {
        int pos = 1;
        for(int j = 0; j < n; j++) {
            if (a[i][j] < a[i][pos] && i != j)
                pos = j;
        }
        for(int j = 0; j < n; j++)
            if (abs(a[i][j] - a[pos][j]) != a[pos][i])
                ok = false;
    }
    
    if (ok)
        puts("YES");
    else
        puts("NO");
    return 0;
}