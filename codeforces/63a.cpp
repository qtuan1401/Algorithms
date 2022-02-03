#include<bits/stdc++.h>

using namespace std;
 
map < string, string > mp;
 
int main() {
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "child")
		    s2 = "woman";
		
		mp[s2] += s1 + "\n";
	}
	cout << mp["rat"] << mp["woman"] << mp["man"] << mp["captain"];
    return 0;
}