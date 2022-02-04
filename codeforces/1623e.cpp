#include <bits/stdc++.h>

using namespace std;

struct Node {
    int l, r;
};

vector < Node > node;

string origin, s, ans;
vector < bool > isDuplicated, shouldDup;
int n, k, len;

void dfs(int u) {
    int l = node[u].l, r = node[u].r;
    if (l != -1) dfs(l);
    origin += s[u];
    if (r != -1) dfs(r);
}

int dupDepth = -1;

void move(int u, int depth, bool canDup) {
    int l = node[u].l, r = node[u].r;
    if (l != -1) move(l, depth + 1, canDup);

    len++;
    bool dup = false;
    if (!canDup) {
        ans += s[u];
    } else {
        if (dupDepth > depth) {
            ans += s[u];
            ans += s[u];
            dupDepth = depth;
            dup = true;
        } else if (shouldDup[len - 1] && k - (depth - dupDepth) >= 0) {
            ans += s[u];
            ans += s[u];
            k -= depth - dupDepth;
            dupDepth = depth;
            dup = true;
        } else {
            ans += s[u];
            dup = false;
        }
    }

    if (r != -1) move(r, depth + 1, canDup && dup);  
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    node.resize(n); isDuplicated.resize(n, false); shouldDup.resize(n, false);
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> node[i].l >> node[i].r;
        node[i].l--; node[i].r--;
    }
    dfs(0);
    for (int i = n - 2; i >= 0; i--)
        if (origin[i] == origin[i + 1])
            shouldDup[i] = shouldDup[i + 1];
        else    
            shouldDup[i] = (origin[i] < origin[i + 1]);
    move(0, 0, true);
    cout << ans << '\n';
    return 0;
}