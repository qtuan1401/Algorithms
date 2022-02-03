#include <bits/stdc++.h>

using namespace std;

long long x[100], y[100], xs, ys, t, ax, ay, bx, by;

long long dist(long long ax, long long ay, long long bx, long long by) {
    return abs(ax - bx) + abs(ay - by);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t; 	
    int ans = 0; int num = 1;
	for( ; x[num - 1] <= 3e16 && y[num - 1] <= 3e16; num++){
		x[num] = x[num - 1] * ax + bx;
		y[num] = y[num - 1] * ay + by;	
    }
	for(int i = 0; i < num; i++) 
		for(int j = 0; j < num; j++) 
            if (dist(xs, ys, x[i], y[i]) + dist(x[i], y[i], x[j], y[j]) <= t)
				ans = max(abs(i - j) + 1, ans);
    cout << ans;
}