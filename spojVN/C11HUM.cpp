#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define md 20001000
priority_queue<ii, vector<ii>, greater<ii> > heap;
int a[md],n,k;
main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        heap.push(ii(a[i],i));
    for(int i=1;i<n;i++)
    {
        int val=heap.top().first;
        int id=heap.top().second;
        heap.pop();
     //   cout << val <<" "<<id<<endl;
        //if (heap.size()<md)
       // {
            for(int j=id;j<=k;j++)
            {
                if ((long long)val*(long long)a[j]<=INT_MAX)
                    heap.push(ii(val*a[j],j));
            }
        //}
    }
    printf("%d",heap.top().first);
}
