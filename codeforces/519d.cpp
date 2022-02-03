#include<bits/stdc++.h>

using namespace std;

map < long long, long long> mp[26];
long long sum, res, x[26];
string s;

int main() {
    ios_base::sync_with_stdio(0);
	for(int i = 0; i < 26; i++) 
        cin >> x[i];
	cin >> s;
    for(int i = 0; i < s.size(); i++) {
        res += mp[s[i] - 'a'][sum];
        mp[s[i] - 'a'][sum += x[s[i] - 'a']]++;
    }
    cout << res;
    return 0;
}