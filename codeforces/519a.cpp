#include <bits/stdc++.h>

using namespace std;

int sum;
string a = "30000000000030195";
int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            if (c != '.') {
                if (c < 'a')
                    sum += a[c - 'B'] - '0';
                else
                    sum -= a[c - 32 - 'B'] - '0';
            }
        }
    }
    cout << (sum > 0 ? "White" : sum ? "Black" : "Draw");
}