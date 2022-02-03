#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector < vector < int > > a(h, vector < int > (w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}