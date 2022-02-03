#include <iostream>
#include <algorithm>
using namespace std;
long long int set1[70000],set2[70000];
long long int a[100],b[100],n,na,nb,ns1,ns2,mini,nummini,Tsum,nset;
long long int getsum(long long int *a,long long int id)
{
    long long int res = 0,i;
    for (i = 0;id != 0;++i,id >>= 1)
    if (id & 1) res += a[i];
    return res;
}
void solve()
{
    long long int dif,val,finder,i,j,lowb,uppb;
    ns1 = (1 << na);
    for (i = 0;i < ns1;++i) set1[i] = getsum(a,i);
    ns2 = (1 << nb);
    for (i = 0;i < ns2;++i) set2[i] = getsum(b,i);
    sort(set2,set2 + ns2);
    mini = -1;
    for (i = 0;i < ns1;++i)
    {
        if (mini != -1) lowb = (Tsum - mini) / 2 - set1[i]; else lowb = 0;
        uppb = Tsum / 2 + 1 - set1[i];
        lowb = lower_bound(set2, set2 + ns2, lowb) - set2;
        uppb = upper_bound(set2, set2 + ns2, uppb) - set2;
        for (j=max(lowb - 1,0LL);j < uppb;++j)
        {
            val = set1[i] + set2[j];
            dif = abs(Tsum - val - val);
            if ((dif == mini) && (nset == val)) ++nummini;
            else if ((dif < mini) || (mini == -1))
            {
                nset = val;
                mini = dif;
                nummini = 1;
            }
        }
    }
    if (mini == 0) nummini = nummini / 2;
}
int main()
{
    int i;
    cin >> n;
    na = n/2;
    nb = n - na;
    Tsum = 0;
    for (i = 0;i < na;++i)
    {
        cin >> a[i];
        Tsum += a[i];
    }
    for (i = 0;i < nb;++i)
    {
        cin >> b[i];
        Tsum += b[i];
    }
    solve();
    cout << mini << " " << nummini;
    return 0;
}
