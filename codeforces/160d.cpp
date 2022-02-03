#include <bits/stdc++.h>
    
using namespace std;
    
const int md = 1e6 + 10;
    
struct node {
    int u, v, id;
    node(int a = 0, int b = 0, int c = 0) {
        u = a;
        v = b;
        id = c;
    }
};
    
typedef pair<int, int> ii;
    
int low[md], num[md], check[md], lab[md], vv[md];
int n, m, cnt;
bool vis[md];
vector< node > edge[md];
vector< ii > adj[md];
    
void bridge(int u) {
    low[u] = num[u] = ++cnt;
    for(vector<ii>::iterator it=adj[u].begin();it!=adj[u].end();it++) {
        int v = (*it).first;
        int id = (*it).second;
        if (vis[id])
            continue;
        vis[id] = true;
        //if (v != p) {
            if (num[v] != 0)
                low[u] = min(low[u], num[v]);
            else {
                bridge(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v]) {
                    check[id] = 1;
                }
            }
        //}
    }
}
    
void Union(int i, int j) {
    int temp = lab[i] + lab[j];
    if (lab[i] < lab[j]) {
        lab[j] = i;
        lab[i] = temp;
    } else {
        lab[i] = j;
        lab[j] = temp;
    }
}
    
inline int root(int u){
    if (lab[u]==u) return u;
    return (lab[u]=root(lab[u]));
}
    
    
inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *___end = buf;
    if(p == ___end) {
        if((___end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}
inline int ReadInt(int *x) {
    static char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
    
    
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[w].push_back(node(u, v, i));
    }
    for(int i=1;i<=n;i++)
        lab[i] = i;
    for(int i=1;i<=1000000;i++) {
        int r = 0;
        for(vector<node>::iterator it=edge[i].begin();it!=edge[i].end();it++) {
            int u = root((*it).u);
            int v = root((*it).v);
            if (u == v) 
                continue;
            //lab[u] = v;
            num[u] = num[v] = 0;
            check[(*it).id] = 2;
            vv[++r] = u;
            vv[++r] = v;
            adj[u].push_back(ii(v, (*it).id));
            adj[v].push_back(ii(u, (*it).id));
        	//cout << u <<" " << v << " " << (*it).id <<endl;
        }
        for(int j=1;j<=r;j++) {
            int u = vv[j];
        //	cout << vv[j] << " ";
        //	cout << num[u] << endl;
            if (!num[u])
                bridge(u);
        }
        //if (r != 0)
        //	cout << r << endl;
    
        for(int j=1;j<=r;j++)
            adj[vv[j]].clear();
        for(vector<node>::iterator it=edge[i].begin();it!=edge[i].end();it++) {
            int u = root((*it).u);
            int v = root((*it).v);
            if (u != v) 
                lab[u] = v;
        }
    }
    for(int i=1;i<=m;i++) {
        if (check[i] == 0)
            puts("none");
        else if (check[i] == 1)
            puts("any");
        else
            puts("at least one");
    }
    return 0;
}