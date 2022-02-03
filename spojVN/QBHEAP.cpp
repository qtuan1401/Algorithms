#include <bits/stdc++.h>
#define forr(i,a,b) for(long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
priority_queue<int> pq;
vector<int> ans;
string s;
long Change(string s)
{
    long n=0;
    forr(i,1,s.size()-1) n=n*10+(s[i]-'0');
    return n;
}
int main()
{
//    freopen(fi,"r",stdin);
 //   freopen(fo,"w",stdout);
    //ios::sync_with_stdio(false);
    cin.tie(0);
	while (!pq.empty()) pq.pop();
    while (cin >> s)
    {
        if (s[0]=='+')
        {
            long n=Change(s);
            if (pq.size()<15000) pq.push(n);
        }
        else if (s[0]=='-' && !pq.empty())
        {
            int n=pq.top();
            pq.pop();
            while (pq.top()==n && !pq.empty()) pq.pop();
        }
    }
    while (!pq.empty())
    {
        int n=pq.top();
        pq.pop();
        ans.push_back(n);
        while (pq.top()==n && !pq.empty()) pq.pop();
    }
    cout << ans.size() << endl;
    forr(i,0,ans.size()-1) cout << ans[i] << ' ';
    return 0;
}

