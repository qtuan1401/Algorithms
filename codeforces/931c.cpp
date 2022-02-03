#include <bits/stdc++.h>
using namespace std;
 
int a[100010], v[3];
int n; 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        v[a[i] - a[0]]++;
    int mn = min(v[0], v[2]);
    if(v[1] && v[0] && v[2] && v[1] / 2 > mn)
    {
        cout << n - v[1] / 2 * 2 << '\n';
        v[0] += v[1] / 2;
        v[2] += v[1] / 2;
        v[1] %= 2;
    } else {
        cout << n - mn * 2 << '\n';
        v[0] -= mn; v[2] -= mn; v[1] += mn * 2;
    }
    for(int i = 0; i < 3; i++ )
        for(int j = 0; j < v[i]; j++)
            cout << a[0] + i << " ";
}
 