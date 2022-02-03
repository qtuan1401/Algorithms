#include <bits/stdc++.h>

using namespace std;

void findMin() {
    dq.clear();
    for (int i = 1; i <= n; i++) {
        while (dq.size() && a[dq.front()] <= a[i]) 
            dq.pop_front();
        if (dq.size()) 
            l[i] = dq.front() + 1;
        else l[i] = i;
        dq.push_front(i);
    }

    dq.clear();
    for (int i = n; i >= 1; i--) {
        while (dq.size() && a[dq.front()] <= a[i]) dq.pop_front();
        if (dq.size()) r[i] = dq.front() - 1;
        else r[i] = i;
        dq.push_front(i);
    }
}

void findMax() {
    dq.clear();
    for (int i = 1; i <= n; i++) {
        while (dq.size() && a[dq.front()] >= a[i]) 
            dq.pop_front();
        if (dq.size()) 
            l[i] = dq.front() + 1;
        else l[i] = i;
        dq.push_front(i);
    }

    dq.clear();
    for (int i = n; i >= 1; i--) {
        while (dq.size() && a[dq.front()] >= a[i]) dq.pop_front();
        if (dq.size()) r[i] = dq.front() - 1;
        else r[i] = i;
        dq.push_front(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    findMax();
    findMin();

    
    return 0;
}