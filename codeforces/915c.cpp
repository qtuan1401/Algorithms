#include <bits/stdc++.h>

using namespace std;

string a, b;

bool check(string a, string b, int i) {
    //string s1 = a;
    //string s2 = b;
    a.erase(i, 1);
    b.erase(0, 1);
    sort(a.begin(), a.end());
    return (a < b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    string s1 = a;
    string s2 = b;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) {
        cout << b;
        return 0;
    }
    string res = "";
    int n = a.size();
    sort(a.begin(), a.end(), greater < int >());
    //cout << a << endl;
    if (a.size() < b.size())
        cout << a;  
    else {
        for(int num = 0; num < n; num++) {
            for(int i = 0; i < a.size(); i++) {
                if (a[i] <= b[0]) {
                    if (a[i] == b[0] && check(a, b, i)) {
                        res += a[i];
                        a.erase(i, 1);
                        b.erase(0, 1);
                        break;
                    } else if (a[i] < b[0]) {
                        cout << res << a[i];
                        for(int j = 0; j < a.size(); j++)
                            if (j != i)
                                cout << a[j];
                        return 0;
                    }
                }
            }
            //cout << res << " " << a << endl;
        }
    }
    return 0;
}