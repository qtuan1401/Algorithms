#include <bits/stdc++.h>
#define task "test"
#define fi task".inp"
#define fo task".out"
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define forl(i,a,b) for(int i=(a);i>=(b);i--)
#define maxN int(1e5)+1
#define INF int(1e9)+1
#define Memset(a,value) memset(a,value,sizeof(a))
#define Forr(i,a) for(vector<int>:: iterator i=(a).begin();i!=(a).end();i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type,vector<type>,greater<type> >
min_heap(iii) heap;
int a[maxN],b[maxN],n,m,k;
main()
{
	ios::sync_with_stdio(0);
    //freopen(fi,"r",stdin);
   // freopen(fo,"w",stdout);
    cin >> n >> m >> k;
    forr(i,1,n)
        cin >> a[i];
    forr(i,1,m)
        cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    forr(i,1,m)
        heap.push(iii(a[1]+b[i],ii(1,i)));
    forr(i,1,k)
    {
        int x=heap.top().first;
        int y=heap.top().second.first;
        int z=heap.top().second.second;
        heap.pop();
       // cout << x << " " <<y << " "<<z<<"\n";
       cout << x << "\n";
        heap.push(iii(a[y+1]+b[z],ii(y+1,z)));
    }
}

