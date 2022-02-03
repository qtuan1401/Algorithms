#include<bits/stdc++.h>

const int md = 1e5 + 5;

using namespace std;
char s[md];
int ans1[md], ans2[md];
int n;
int cmp(int *x,int *y) {
    for(int i = md - 1; i >= 1; i--){
        if (x[i] > y[i])
            return 0;
        else if (x[i] < y[i])
            return 1;
    }
    return 1;
}
void print(int *x){
    int check = 0;
    for(int i = md - 1; i >= 1; i--){
        if(x[i])
            check = 1;
        if (check)
            printf("%d", x[i]);
    }
}
void add(int a, int b, int c, int d, int *x){
    for(int i = d, j = b, k = 1; i>=c || j >= a; i--, j--, k++) {
        if (i >= c) x[k] += s[i] - '0';
        if (j >= a) x[k] += s[j] - '0';
    }
    for(int i = 1;i < md; i++) {
        x[i + 1] += x[i] / 10;
        x[i] %= 10;
    }
}
int main(){
    //freopen("test.in", "r", stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    int x = (n + 1) / 2, y = n / 2 + 1;
    while (y <=n && s[y] == '0')
        y++;
    while (x >= 1 && s[x + 1] == '0')
        x--;
    if (s[x + 1] != '0')
        add(1, x, x + 1, n, ans2);
    if(s[y] != '0')
        add(1, y - 1, y, n, ans1);

    if (cmp(ans1, ans2))
        print(ans1);
    else print(ans2);
    return 0;
}