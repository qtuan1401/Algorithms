#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
	int cntB = b, cntA = a, res = 0;
	for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            if (cntA && cntB < b) {
                cntA--;
                cntB++;
            } else {
                cntB--;
            } 
        } else {
            if (cntB)
                cntB--;
            else
                cntA--;        
        }
        if (cntB < 0 || cntA < 0) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}