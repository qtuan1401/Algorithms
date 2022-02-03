#include <bits/stdc++.h>

using namespace std;


string s,t;
int z[1500000];

int main()
{
    getline(cin,s);
    getline(cin,t);
    s = t + "#" + s;
    int i;int l = 0, r = 0, n = s.length(), m = t.length();
    for (i=1;i<n;i++)
    {
        if(i<=r)
            z[i]=min(z[i-l],r-i+1);
        while (i+z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i]-1>r)
        {
            l = i;
            r=i+z[i]-1;
        }
    }
    for (i=m-1;i<n;i++)
    if (z[i] == m) cout << i-m << " ";
    return 0;
}

