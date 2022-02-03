#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
    cin >> T;
	while (T--) {
        string x, y;
        cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int posX = 0, posY = 0;
        while (y[posY] != '1')
            posY++;
        posX = posY;
        while (x[posX] != '1')
            posX++;
        cout << posX - posY << '\n';
	}
}