#include <bits/stdc++.h>

using namespace std;
bool kt[500000]={false};
long long a[500000];
long long s,mi,n,i,j,k,res;
int main()
{
    cin >> n>>s;
     a[0]=0;
     mi=0;
     for (i=1;i<=n;i++)
     {
         cin >> k;
         a[i]=a[i-1]+k;
         if (a[i]<mi)
         {
             mi=a[i];
             kt[i]=true;
         }
     }
     res=-1;k=n;
     for (i=n;i>=0;i--)
        if (kt[i])
            while (k>i)
            {
                if (a[k]-a[i]>=s)
                {
                    if (k-i>res) res=k-i;
                    break;
                }
                k--;
            }
    cout << res;
    return 0;
}
