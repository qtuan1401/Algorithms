#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 10;

char a[md], b[md];
int n;
long long c;

long long bigmod(char *a, long long c) {
	long long carry = 0;
	n = strlen(a);
	for(int i=0;i<n;i++)
		carry = ((a[i] - '0') + carry*10) % c;
	return carry;
}

long long calc(long long a, int n) {
	long long res = 1;
	while (n) {
		if (n & 1) 
			res = (res * a) % c;
		a = (a * a) % c;
		n /= 2;
	}

	return res;
}

int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%s", a);
	scanf("%s", b);
	scanf("%lld", &c);

	long long d = bigmod(a, c);

	long long res = 1;
	n = strlen(b);
	for(int i=0;i<n;i++) {
		int k = b[i] - '0';
		res = (calc(res, 10) * calc(d, k)) % c;
	}

	printf("%lld", res);
	return 0;
}