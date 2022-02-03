#include <bits/stdc++.h>
#include <list>
using namespace std;
 
int n;
vector<int> a;
 
void Init()
{
    scanf("%d",&n);
    a.resize(n+2);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}
 
bool KiemTra(int t)
{
    double d=8*t+1;
    double x=(-1+sqrt(d))/2;
    if(x-(int)x==0) return true;
    return false;
}
void Solve()
{
    int res=0;
    int dem=0;
    for (int i=1;i<=n;i++)
    {
        if(KiemTra(a[i]))
        {
            if(dem==0 || (dem>0 && a[i]>=a[i-1]))
                dem++;
            else
            {
                res=max(res,dem);
                dem=1;
            }
        }
        else
        {
            res=max(res,dem);
            dem=0;
        }
    }
    res=max(res,dem);
    printf("%d",res);
}
 
int main()
{
    Init();
    Solve();
}