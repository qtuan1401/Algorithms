#include <iostream>

using namespace std;

const int MAXN = 5e5 + 10;

long long dMin[MAXN * 2], dMax[MAXN * 2], l[MAXN], r[MAXN], ansLeft[MAXN], ansRight[MAXN];
long long sumLeft[MAXN], sumRight[MAXN], a[MAXN];
int n;

void findMinMax() {
	int topMax = 0, topMin = 0;
	dMin[0] = 0;
	for(int i = 1; i <= n; i++) {
		while (topMin > 0 && a[dMin[topMin]] >= a[i])
			topMin--;
		l[i] = dMin[topMin] + 1;
		dMin[++topMin] = i;
	}
	dMax[0] = n + 1;
	for(int i = n; i >= 1; i--) {
		while (topMax > 0 && a[dMax[topMax]] >= a[i])
			topMax--;
		r[i] = dMax[topMax] - 1;
		dMax[++topMax] = i;
	}
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	findMinMax();
	for(int i = 1; i <= n; i++) 
		sumLeft[i] = sumLeft[l[i] - 1] + a[i] * (i - l[i] + 1);
	for(int i = n; i >= 1; i--)
		sumRight[i] = sumRight[r[i] + 1] + a[i] * (r[i] - i + 1);
	long long mxSum = 0; int pos = 0;
	for(int i = 1; i <= n; i++) {
		if (sumLeft[i] + sumRight[i] - a[i] > mxSum) {
			mxSum = sumLeft[i] + sumRight[i] - a[i];
			pos = i;
		}
	}	
	ansLeft[pos] = ansRight[pos] = a[pos];
	for(int i = pos - 1; i >= 1; i--) 
		ansLeft[i] = min(ansLeft[i + 1], a[i]);
	for(int i = pos + 1; i <= n; i++)
		ansRight[i] = min(ansRight[i - 1], a[i]);
	for(int i = 1; i <= pos; i++)
		cout << ansLeft[i] << " ";
	for(int i = pos + 1; i <= n; i++)
		cout << ansRight[i] << " ";
	return 0;
}