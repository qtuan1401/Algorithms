#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    multiset < int > lenX, lenY;
    set < int > cutX, cutY;
    cutX.insert(0); cutX.insert(w);
    cutY.insert(0); cutY.insert(h);
    lenX.insert(w); lenY.insert(h);
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'V') {
            cutX.insert(x);
            set < int > :: iterator it = cutX.find(x);
            int l = *(--it);
            int r = *(++(++it));
            lenX.erase(lenX.find(r - l));
            lenX.insert(x - l);
            lenX.insert(r - x);
        } else {
            cutY.insert(x);
            set < int > :: iterator it = cutY.find(x);
            int l = *(--it);
            int r = *(++(++it));
            lenY.erase(lenY.find(r - l));
            lenY.insert(x - l);
            lenY.insert(r - x);
        }
         cout << 1ll * (*lenX.rbegin()) * (*lenY.rbegin()) << '\n';
    }
    return 0;
}