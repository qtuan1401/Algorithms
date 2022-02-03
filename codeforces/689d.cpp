#include <bits/stdc++.h>
using namespace std;

const int LIM = 2e5 + 5;

int a[LIM], b[LIM];
deque <int> mx, mn;
int n;

void push(int i) {
    while(!mx.empty() and a[mx.back()] <= a[i]) mx.pop_back();
    while(!mn.empty() and b[mn.back()] >= b[i]) mn.pop_back();
    mx.push_back(i);
    mn.push_back(i);
}

void pop(int i) {
    while (!mx.empty() and mx.front() < i) mx.pop_front();
    while (!mn.empty() and mn.front() < i) mn.pop_front();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    long long res = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        push(i);
        while (j <= i && a[mx.front()] - b[mn.front()] > 0) {
            j++;
            pop(j);
        }
        if (!mx.empty() && !mn.empty() && a[mx.front()] == b[mn.front()]) 
            res += min(mx.front(), mn.front()) - j + 1;
    }
    cout << res;
}