#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,i,j,a[1001][1001],dd[2000000];
string s;
int main()
{
	cin >> n >> m;
	for(i=1;i<=n;i++)
	{
        cin >> s;
        for(j=0;j<s.size();j++) a[i][j+1]=int(s[j])-48;
	}
	for(j=1;j<=m;j++) a[n+1][j]=1;
 	ll Max=LONG_LONG_MIN;
	for (j=1;j<=m;j++)
	{
		ll d=0;
		for(i=1;i<=n+1;i++)
			if (a[i][j]==0) d++;
				else
				{
                    dd[d]++;
                    if (d>Max) Max=d;
                    d=0;
				}
	}
	for(i=1;i<=Max;i++)
        if (dd[i]!=0) cout << i << " " << dd[i] << endl;
    getchar();
}
