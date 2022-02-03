#include <bits/stdc++.h>
    
using namespace std;

int a[200001];
long long neg[200001], pos[200001]; 
long long res, rneg, rpos;
int n, x;
    
    
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x > 0) a[i] = 1;
        else a[i] = -1;
    }
    pos[1] = rpos = (a[1] > 0);
    neg[1] = rneg = (a[1] < 0);
    for(int i = 2; i <= n; i++) {
        if(a[i] > 0) {
            pos[i] = pos[i - 1] + 1;
            neg[i] = neg[i - 1];
        } else {
            pos[i] = neg[i - 1];
            neg[i] = pos[i - 1] + 1;
        } 
        rpos += pos[i];
        rneg += neg[i];
    }

    cout << rneg << " " << rpos;
    return 0;
}