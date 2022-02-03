#include <bits/stdc++.h>
using namespace std;
long long n=0,a[100000];
long long int s=1;
int main()
{
	cin >> n;
	for(long long i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) s*=a[i]-i+1;
	cout << s;
}
