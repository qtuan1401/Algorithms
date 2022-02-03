#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    long long sum = (1 << s.size()) - 1;
    for(int i = 0; i < s.size(); i++)
        if (s[s.size() - 1 - i] == '7')
            sum += (1 << i);
    cout << sum;
    return 0;
}