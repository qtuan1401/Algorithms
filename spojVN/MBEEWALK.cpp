#include <bits/stdc++.h>
//#include <cstdio>
long long int Count[17][17][17],res[17],n;
using namespace std;
int main() {
	Count[0][8][8]=1;
	for(int k=1;k<=14;k++)
	{
		for(int i=1;i<=16;i++)
			for(int j=1;j<=16;j++)
				Count[k][i][j]=Count[k-1][i][j+1]+Count[k-1][i][j-1]+Count[k-1][i-1][j+1]+Count[k-1][i-1][j]+Count[k-1][i+1][j]+Count[k-1][i+1][j-1];
		res[k]=Count[k][8][8];
	}			
	scanf("%d",&n);
	while (n--)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",res[k]);
	}
}