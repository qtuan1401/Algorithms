#include <bits/stdc++.h>

using namespace std;


int n, x[105][2];
string s[2];

int main() {
    ios_base::sync_with_stdio(0);
	cin >> s[0] >> s[1];
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, m;
        char c1, c2;
		cin >> t >> c1 >> m >> c2;
		int p = (c1 == 'a');
		if (x[m][p] < 2) {
            if(!x[m][p] && c2 == 'y') 
                x[m][p]++;
			else {
                x[m][p] = 2;
                cout << s[p] << " " << m << " " << t << '\n'; 
            }
        }			
	}
}
