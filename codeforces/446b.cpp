#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 10;

int n, m, k, p;
priority_queue < int > heapRow, heapCol;
int a[MXN][MXN];
long long sumRow[MXN * MXN], sumCol[MXN * MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> p;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++)
            sum += a[i][j];
        heapRow.push(sum);
    }

    for(int i = 1; i <= k; i++) {
        sumRow[i] = heapRow.top(); heapRow.pop();
        heapRow.push(sumRow[i] - m * p);
    }

    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += a[i][j];
        heapCol.push(sum);
    }

    for(int i = 1; i <= k; i++) {
        sumCol[i] = heapCol.top(); heapCol.pop();
        heapCol.push(sumCol[i] - n * p);
    }

    //for(int i = 0; i < n; i++)
    //    cout << sumRow[i] << " ";
    //for(int i = 0; i < m; i++)
    //    cout << sumCol[i] << " ";
    for(int i = 1; i <= k; i++)
        sumRow[i] += sumRow[i - 1];
    for(int i = 1; i <= k; i++)
        sumCol[i] += sumCol[i - 1];

    long long res = -1e18;
    for(int i = 0; i <= k; i++)
        res = max(res, sumRow[i] + sumCol[k - i] - 1ll * i * (k - i) * p);
    cout << res;
    return 0;
}