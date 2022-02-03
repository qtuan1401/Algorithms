#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector < int > num;
    for (int i = 1; i <= k + 1; i++) {
        cout << "? ";
 
        for (int j = 1; j <= k + 1; j++) 
            if (j != i) 
                cout << j << " ";
        cout << endl;
        int pos, val;
        cin >> pos >> val;
        num.push_back(val);
    }

    int mx = *max_element(num.begin(), num.end());
    int cnt = 0;
    for(int i = 0; i < num.size(); i++)
        cnt += (num[i] == mx);
    cout << "! " << cnt << endl;
    return 0;
}