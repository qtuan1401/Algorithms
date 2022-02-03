#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e6 + 5;
const ll base = 1e9 + 7;
string a,b;
int l,r,u,v,q,n,m;
ll HashA[maxN], HashB[maxN], Pow[maxN];
int calcA(int l, int r)
{
	return ((HashA[r]-HashA[l-1]*Pow[r -l+1])%base+base)%base;
}
int calcB(int l, int r)
{
	return((HashB[r]-HashB[l-1]*Pow[r-l+1])%base+base)%base;
}
char Process(int la, int ra, int lb, int rb){
	if (ra - la == rb - lb)
		if (calcA(la, ra) == calcB(lb, rb)) return '=';
	int l = 0, r = min(ra - la, rb - lb), mid;
	while (l <= r){
		mid = (l + r) >> 1;
		if (calcA(la, la + mid) == calcB(lb, lb + mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (la+l>ra) return '<';
	if (lb+l>rb) return '>';
	if (a[la+l]<b[lb+l]) return '<';
	return '>';
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> b;
    a='#'+a;
    b='#'+b;
    Pow[0]=1;
    for(int i=1;i<=maxN;i++)
        Pow[i]=(Pow[i-1]*26)%base;
    for(int i=1;i<=n;i++)
		HashA[i]=(HashA[i-1]*26 + a[i]-'a')%base;
    for(int i=1;i<=m;i++)
		HashB[i]=(HashB[i-1]*26 + b[i]-'a')%base;
	cin  >> q;
	while (q--)
    {
        cin >> l >> r >> u >> v;
        cout << Process(l,r,u,v);
    }
}
