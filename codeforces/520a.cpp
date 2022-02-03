#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    set < char > s; 
    int n; char c;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.insert(tolower(c));
    }
    if (s.size() == 26)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}