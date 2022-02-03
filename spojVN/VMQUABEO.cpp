#include <bits/stdc++.h>
using namespace std;
#define md int(1e6)+2
typedef pair<int,int>ii;
int a[md],L,d,n,r,l,rl,rp;
long long res;
priority_queue<ii> hmax;
priority_queue<ii, vector<ii>, greater<ii> > hmin;
deque<int> dmax,dmin;
inline void push(int i)
{
    while (!dmax.empty() && a[dmax.back()]<a[i])
        dmax.pop_back();
    dmax.push_back(i);
    while (!dmin.empty() && a[dmin.back()]>a[i])
        dmin.pop_back();
    dmin.push_back(i);
}
inline void pop(int i)
{
    while (!dmax.empty() && dmax.front()<i)
        dmax.pop_front();
    while (!dmin.empty() && dmin.front()<i)
        dmin.pop_front();
}
main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d%d%d",&n,&L,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    L++;
    res=0;
    for(int i=1;i<=L;i++)
        push(i);
    r=L;
    for(int i=1;i<=n;i++)
    {
        pop(i);
        //if (hmax.top().first-hmin.top().first<=d && r-i+1>=L)
         //   res++;
       // if (i==4)
        //{
            //cout << hmax.top().first-hmin.top().first<< " "<<r-i+1 << endl;
        //}
        //cout << i << " "<<r<<" "<<res<<endl;
        //rl=hmin.top().second;
        //rp=hmax.top().second;
        while (true)
        {
        	if (r==n)
            	break;
            pop(i);
            //cout << i << " "<<r<<endl;
            int Max,Min;
            if (!dmax.empty())
                Max=a[dmax.front()];
            else Max=0;
            if (!dmin.empty())
                Min=a[dmin.front()];
            else Min=int(1e9);
            //cout <<Max << " "<<Min <<" " ;
            if (r<n) r++;
            //cout << Max<< " "<< Min << " "<<a[r] <<endl;
            if (max(Max,a[r])-min(Min,a[r])<=d)
            {
            /*    if (a[r]>hmax.top().first)
                    rp=r;
                if (a[r]<hmin.top().first)
                    rl=r;*/
                push(r);
            }
            else
            {
                r--;
                break;
            }
         //   cout <<r <<endl;
        }
        if (r-i+1>=L) res+=(r-i+1-L+1);
        //cout <<i << " "<<r<<" "<<res<<" "<<endl;
  //      cout <<r <<endl;
    }
    printf("%lld",res);
}
