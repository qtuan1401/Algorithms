#include <bits/stdc++.h>
using namespace std;  
typedef unsigned long long ull;  
struct point{int x,y;}p[1<<20|1];  
int n,a[21],b[21],cnt,q[1<<20|1],t=1,x,sa,sb;  
ull s = 2ull * LONG_LONG_MAX;  
void dfs(int x, ull l, ull r) {  
    if(x == n + 1) {
        p[++cnt].x = l;
        p[cnt].y = r;
        return;
    }  
    dfs(x + 1,l + a[x], r), dfs(x + 1, l,r + b[x]);  
}  
bool operator < (point a, point b) {
	return a.x == b.x ? a.y > b.y : a.x < b.x;
}  
int main() { 
    ios_base::sync_with_stdio(0); 
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for(int i=1;i<=n;i++)
    	cin >> a[i];
    for(int i=1;i<=n;i++)
    	cin >> b[i];
    int tot=n; n=0;  
    for(int i = 1;i <= tot; i++)  
    	if(!a[i] || !b[i]) 
    		sa += a[i], sb += b[i];  
    else 
    	a[++n] = a[i], b[n] = b[i];  
    dfs(1, 0, 0);  
    sort(p + 1,p + cnt + 1);  
    //for(int i=1;i<=cnt;i++) 
    //    cout << p[i].x << " " << p[i].y << endl;
    for(int i=1;i<=cnt;i++) {  
        while(t && p[q[t]].y <= p[i].y)
        	t--;  
        q[++t] = i;  
    }  
    for(int i=1;i<=t;i++) {  
        ull tmp=(p[q[i - 1]].x + p[q[i]].y + 2);  
        if(tmp < s)
        	s = tmp, x = p[q[i - 1]].x + 1;  
        else if(tmp == s && p[q[i - 1]].x + 1 < x)
        	x = p[q[i - 1]].x + 1;  
    }  
    cout << x + sa <<"\n" << s - x + sb;
    //printf("%d %lld\n",x+sa,s-(LL)x+(LL)sb);  
}  