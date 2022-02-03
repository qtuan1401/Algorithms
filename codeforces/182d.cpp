#include <bits/stdc++.h>

using namespace std;

string a,b;

bool check(string s, int m) {
	for(int i=0; i<s.size(); i++) 
		if(a[i%m] != s[i]) return 0;
	return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    int cnt = 0;
    for(int i = 1; i < a.size() + b.size(); i++)
        if (a.size() % i == 0 && b.size() % i == 0)
            cnt += (check(a, i) && check(b, i));
    cout << cnt;
    return 0;
}