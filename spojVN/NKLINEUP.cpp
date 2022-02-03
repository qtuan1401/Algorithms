#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<int> a;
vector< pair<int,int> > node;
int resmax, resmin;

void Init_Tree(int k, int l, int r, int i)
{
	if(l>i || r<i) return;
	if(l==r)
	{
		node[k]=make_pair(a[i],a[i]);
		return;
	}
	int m=(l+r)/2;
	Init_Tree(2*k,l,m,i);
	Init_Tree(2*k+1,m+1,r,i);
	node[k]=make_pair(max(node[2*k].first, node[2*k+1].first),min(node[2*k].second, node[2*k+1].second));
}

void Init()
{
	scanf("%d%d",&n,&q);
	a.resize(n+2);
	node.resize(4*n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Init_Tree(1,1,n,i);
	}
}

void Query(int k, int l, int r, int A, int B)
{
	if(l>B || r<A) return;
	if(A<=l && B>=r)
	{
		resmax=max(resmax,node[k].first);
		resmin=min(resmin,node[k].second);
		return;
	}
	int m=(l+r)/2;
	Query(2*k,l,m,A,B);
	Query(2*k+1,m+1,r,A,B);
}

void Solve()
{
	for (int i=1;i<=q;i++)
	{
		int A, B;
		scanf("%d%d",&A,&B);
		resmax=0;
		resmin=10000000;
		Query(1,1,n,A,B);
		printf("%d\n",resmax-resmin);
	}
}

int main()
{
	Init();
	Solve();
}
