#include <bits/stdc++.h>

using namespace std;
//1,1  1,2  1,3  1,4
//2,1  2,2  2,3  2,4
//3,1  3,2  3,3  3,4
//4,1  4,2  4,3  4,4

//(x, y)       (x, y + 1)
//(x + 1, y)   (x + 1, y + 1)

/*
(-1, -1) (-1, 0) (-1, 1)
(0, -1)  (0, 0)  (0, 1)
(1, -1)  (1, 0)  (1, 1)
*/

int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

int check[370][5][5][7][7][7][7], cnt;
int dp[366][5][5][8][8][8][8];
int busy[370][20];
int n;

inline bool fail(int x, int y, int i) {
    return busy[i][(x - 1) * 4 + y];
}

bool f(int i, int x, int y, int i1, int i4, int i13, int i16, int checked=0) {
 //   cout << u <<" " << x << " " << y<<" " << i1 <<" " << i4 <<" " << i13 << " " << i16 <<" " << F[C] << endl;
    if (x < 1 || x > 3 || y < 1 || y > 3)
        return false;
	if (checked == 0) {
		if (i == n + 1)
            return true;
		if (x != 1 || y != 1)
            i1++;
        else i1=0;
		if (x != 1 || y + 1 != 4)
            i4++;
        else i4=0;
		if (x + 1 != 4 || y != 1)
            i13++;
        else i13=0;
		if (x + 1 != 4 || y + 1 != 4)
            i16++;
        else i16=0;
		if (fail(x, y, i) || fail(x+1, y+1, i)) return false;
		if (fail(x+1, y, i) || fail(x, y+1, i)) return false;
		if (i1>=7 || i4>=7 || i13>=7 || i16>=7) return false;
		checked=1;
	}

	if (check[i][x][y][i1][i4][i13][i16] == cnt)
        return dp[i][x][y][i1][i4][i13][i16];
	bool res = false;
	for (int k=0; k<5; k++) {
        int u1 = x + dx[k];
        int v1 = y + dy[k];
        int u2 = u1 + dx[k];
        int v2 = v1 + dy[k];
		res = res || f(i + 1, u1, v1, i1, i4, i13, i16);
		res = res || f(i + 1, u2, v2, i1, i4, i13, i16);
		//res = res || f(u+1, x, i, i1, i4, i13, i16);
	}
	check[i][x][y][i1][i4][i13][i16] = cnt;
	return dp[i][x][y][i1][i4][i13][i16] = res;
}

int main() {
	//freopen("test.inp", "r", stdin);
//	freopen("weather.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n) {
        cnt++;
        if (n == 0)
        	return 0;
        //cout << n << endl;
		//if (n==0) return 0;
		for (int i=1; i<=n; i++)
            for (int j=1; j<=16; j++)
                cin >> busy[i][j];
		cout << f(1, 2, 2, 0, 0, 0, 0) << '\n';
	}
	return 0;
}
