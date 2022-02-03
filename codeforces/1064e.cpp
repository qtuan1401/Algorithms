#include <bits/stdc++.h>

using namespace std;

char s[10];
int n;

int main() {
    scanf("%d", &n);
    char c;
    int l = 0, r = 1e9, mid = 0;
    for(int i = 1; i <= n; i++) {
        printf("1 %d\n", mid);
        fflush(stdout);
        scanf("%s", s);
        if (i == 1)
            c = s[0];
        if (s[0] == c)
            l = mid;
        else r = mid;
        mid = (l + r) >> 1;
    }
    printf("0 %d 2 %d\n", l, r);
    fflush(stdout);
}