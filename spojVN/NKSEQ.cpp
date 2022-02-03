#include <bits/stdc++.h>
using namespace std;
 
long n,a[100100],F[100100],S,res,tmp;
 
int main()
{
    cin >> n;
    F[n+1] = 10000*100000 + 1;  
    for (long i=1;i<=n;i++) {
        cin >> a[i];
        S = S + a[i];  
        tmp += a[i];
        F[n+1] = min(F[n+1],tmp);
    }
    if (S <= 0) {  
        cout << 0;
        return 0;
    }
    if (F[n+1] > 0) res++; 
    for (long i=n;i>=2;i--) { 
        F[i] = min(F[i+1]+a[i],a[i]);
        res+=F[i]>0;
    }
   	cout << res;
    return 0;
}