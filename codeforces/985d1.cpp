#include <bits/stdc++.h>
 
using namespace std;

int n;
map < double, int > mp;
double val[200010];
 
int main() {
    ios_base::sync_with_stdio(0);
	cin >> n;
 
	for (int i = 0; i < n; i++) {
        char q;
        double a, b, c;
		cin >> q >> a >> q >> b >> q >> q >> c;
		val[i] = (a + b) / c;
	    mp[val[i]]++;
	}
    
    for(int i = 0; i < n; i++)
        cout << mp[val[i]] << " ";
	return 0;
}