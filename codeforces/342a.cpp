#include<bits/stdc++.h>

using namespace std;

int n;
int cnt[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (cnt[1] == n / 3 && cnt[2] + cnt[3] == n / 3 && cnt[4] + cnt[6] == n / 3 && cnt[6] >= cnt[3]) {
        for(int i = 0; i < cnt[4]; i++)
			cout << "1 2 4\n";
        for(int i = cnt[4]; i < cnt[2]; i++)
            cout << "1 2 6\n";
        for(int i = 0; i < cnt[3]; i++)
            cout << "1 3 6\n";
    } else {
        cout << "-1";
    }
    return 0;
}