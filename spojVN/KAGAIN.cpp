#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)
deque<int> dq;
int a[md],r[md],l[md],q,n;
inline void solve()
{
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while (!dq.empty() && a[dq.back()]>=a[i])
            dq.pop_back();
        l[i]=dq.back()+1;
        dq.push_back(i);
    }
    dq.push_back(n+1);
    for(int i=n;i>=1;i--)
    {
        while (!dq.empty() && a[dq.back()]>=a[i])
            dq.pop_back();
        r[i]=dq.back()-1;
        dq.push_back(i);
    }
}
main()
{
    scanf("%d",&q);
    while (q--)
    {
        int Max=0,left,right;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        solve();
        for(int i=1;i<=n;i++)
            if (Max<a[i]*(r[i]-l[i]+1))
            {
                Max=a[i]*(r[i]-l[i]+1);
                left=l[i];
                right=r[i];
            }
        printf("%d %d %d\n",Max,left,right);
    }
}
