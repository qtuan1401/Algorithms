#include <bits/stdc++.h>
#define maxN 20
#define maxC 2000000000
     
    using namespace std;
     
    bool fr[maxN];
    int a[maxN][maxN], x[maxN], cmin, res, cost, best;
    int n;
     
    void Try(int i){
        for (int j = 1; j <= n; j++)
        if (fr[j]){
            x[i] = j;
            fr[j] = false;
            cost += a[x[i-1]][j];
            if (i == n){
                if (res > cost) res = cost;
                best = res;
            }
            else
                if (cost + cmin*(n-i+1) < best) Try(i+1);
            cost -= a[x[i-1]][j];
            fr[j] = true;
        }
    }
     
    int main(){
        //freopen("LEM3.INP", "r", stdin);
        //freopen("LEM3.OUT", "w", stdout);
        scanf("%d", &n);
        cmin = maxC;  best = cmin;
        memset(a, 0, sizeof(a));
        x[0] = 0;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            if (a[i][j] < cmin && i != j) cmin = a[i][j];
        }
        res = maxC;
        cost = 0;
        memset(fr, true, sizeof(fr));
        Try(1);
        printf("%d", best);
        return 0;
    }