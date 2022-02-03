#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c >> d;
    int ta = a, tb = b, tc = c, td = d;
    b -= a;
    c -= d;
    if (b < -1 || c < -1) {
        cout << "NO";
    } else if (b == -1) { 
        if (tc > 0 || td > 0)
            cout << "NO";
        else {
            cout << "YES\n";
            cout << "0 ";
            for(int i = 0; i < tb; i++)
                cout << "1 0 ";
        }
    } else if (c == -1) {
        if (ta > 0 || tb > 0)
            cout << "NO";
        else {
            cout <<"YES\n";
            cout << "3 ";
            for(int i = 0; i < tc; i++)
                cout << "2 3 "; 
        }
    } else {
        if (abs(c - b) > 1) {
            cout << "NO";
        } else {
            cout << "YES\n";
            if (b > c)
                cout << "1 ";
            for(int i = 0; i < min(c, b); i++)
                cout << "2 1 ";
            for(int i = 0; i < a; i++)
                cout << "0 1 ";
            for(int i = 0; i < d; i++)
                cout << "2 3 ";
            if (c > b)
                cout << "2 ";
        }
    } 
    return 0;
}