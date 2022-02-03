#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y, w, k;
    node(int _x = 0, int _y = 0, int _w = 0, int _k = 0) {
        x = _x;
        y = _y;
        w = _w;
        k = _k;
    }
    bool operator < (const node & temp) const {
        if (w == a.w)
            return k > temp.k;
        return w < temp.w;
    }
};

void dijsktra(int sx, int sy, int tx, int ty) {
    heap.push(node(sx, sy, 0, 0));
    while (heap.size()) {
        node cur = heap.top();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    dijkstra(sx, sy, tx, ty);
    return 0;
}