#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int na, nb, k, m;
    cin >> na >> nb;
    vector < int > a(na);
    vector < int > b(nb);
    cin >> k >> m;
    for(int i = 0; i < na; i++)
        cin >> a[i];
    for(int i = 0; i < nb; i++)
        cin >> b[i];
    if (a[k - 1] < b[nb - m]) 
        cout << "YES";
    else 
        cout << "NO";
	return 0;
}
