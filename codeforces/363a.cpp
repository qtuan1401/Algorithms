#include<bits/stdc++.h>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
	int n; 
    cin >> n;

	do {
		int temp = n % 10;
		cout << (temp >= 5 ? "-O|" : "O-|");
		temp %= 5;
        for(int i = 0; i < temp; i++)
            cout << 'O';
        cout << '-';
        for(int i = 0; i < 4 - temp; i++)
            cout << 'O';
        cout << '\n';
        n /= 10;
	} while(n > 0);

	return 0;
}