#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+5
deque<int> dq;
int n,k,a[md];
long long res=0,f[md];
inline void push(int i)
{
    while (!dq.empty() && f[i]<f[dq.back()])
        dq.pop_back();
    dq.push_back(i);
}
inline void pop(int i)
{
    while (!dq.empty() && dq.front()<=i)
        dq.pop_front();
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),res+=a[i];
    for(int i=1;i<=k;i++)
        f[i]=a[i];
    for(int i=1;i<=k;i++)
        push(i);
    //=f[dq.front()];
   // cout << f[dq.front()] <<endl;
    for(int i=k;i<=n;i++)
    {
        pop(i-k);
        push(i);
      //  cout << f[dq.front()]<<endl;
        f[i+1]=f[dq.front()]+a[i+1];
    }
    printf("%lld",res-f[n+1]);
}