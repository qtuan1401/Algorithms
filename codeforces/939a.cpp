#include <bits/stdc++.h>

using namespace std;

int n;
int a[5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++)
        if (a[a[a[i]]] == i) {
            //cout << i << " " << a[a[i]] << " " << a[i] << " " << a[a[a[i]]] << endl;
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}