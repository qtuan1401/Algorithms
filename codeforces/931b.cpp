#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    if (a > b)
        swap(a, b);
    int l = 1, r = n, round = log2(n), cnt = 0;
    //cout << round << endl;
    while (l != r) {
        int mid = (l + r) >> 1;
        //cout << mid << " " << a << " " << ./ab << endl;
        if (a <= mid && b > mid) {
            if (log2(n) == round)
                cout << "Final!";
            else 
                cout << round;
            return 0;
        } else if (a <= mid && b <= mid)
            r = mid - 1;
        else 
            l = mid + 1;
        round--;
    }
    cout << round;
    return 0;
}