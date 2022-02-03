#include <iostream>
 
using namespace std;
 
const int MAXN = 1e3 + 10;
 
struct node {
	int x, y;
	bool operator != (const node &a) {
		return (x != a.x || y != a.y);
	}
} a[MAXN][MAXN];
 
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char dir[] = {'L', 'U', 'R', 'D'};
char ans[MAXN][MAXN];
bool blocked[MAXN][MAXN];
int n;
 
void dfs(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > n || ans[nx][ny] != '#' || blocked[nx][ny])
			continue;
		if (a[nx][ny] != a[x][y])
			continue;
		//cout << x << " " << y << " " << nx << " " << ny << endl;
		//cout << a[nx][ny].x << " " << ans[x][y]
		ans[nx][ny] = dir[i];
		dfs(nx, ny);
	}
}
 
int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j].x >> a[i][j].y;
			if (a[i][j].x != -1 && a[i][j].y != -1) 
				blocked[a[i][j].x][a[i][j].y] = true;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans[i][j] = '#';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
			if (blocked[i][j]) {
				if (a[i][j].x != i || a[i][j].y != j) {
					cout << "INVALID";
					return 0;
				}
				dfs(a[i][j].x, a[i][j].y);
			}
	for(int x = 1; x <= n; x++) {
		for(int y = 1; y <= n; y++) {
			if (a[x][y].x == -1 && a[x][y].y == -1) {
				if (ans[x][y] != '#')
					continue;
				for(int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 1 || nx > n || ny < 1 || ny > n || ans[nx][ny] != '#' || blocked[nx][ny])
						continue;
					if (a[nx][ny] != a[x][y])
						continue;
					//cout << x << " " << y << " " << nx << " " << ny << endl;
					ans[nx][ny] = dir[k];
					ans[x][y] = dir[(k + 2) % 4];
					dfs(nx, ny);
					dfs(x, y);
					break;
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cnt += (ans[i][j] != '#' || blocked[i][j]);
	if (cnt != n * n) 
		cout << "INVALID";
	else {
		cout << "VALID\n";
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if (blocked[i][j])
					cout << "X";
				else cout << ans[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}