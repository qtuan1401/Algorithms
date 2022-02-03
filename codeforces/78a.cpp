#include <bits/stdc++.h>

using namespace std;

const int x[] = {5, 7, 5};

int main() {
    for(int i = 0; i < 3; i++) {
        int sum = 0;
        string s;
        getline(cin, s);
        for(int j = 0; j < s.size(); j++)
            sum += (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u');
        if (sum != x[i]) {
            cout << "NO";
            return 0;
        } 
    }
    cout << "YES";
    return 0;
}