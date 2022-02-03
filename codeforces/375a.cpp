#include <bits/stdc++.h>

using namespace std;

int cnt[10];
int mod[] = {1869, 6198, 1896, 1689, 1986, 1968, 1698};
int remain;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) 
        cnt[s[i] - '0']++;
    cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;
    for(int i = 1; i <= 9; i++) {
        while (cnt[i]--) {
            remain = (remain * 10 + i) % 7;
            cout << i;
        }
    }
    cout << mod[remain];
	while (cnt[0]--)
        cout << 0;
    return 0;
}