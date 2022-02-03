#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

deque < int > dq;
int a[MAXN];
long long f[MAXN];
int n, k;

void dqPush(int i) {
    while (!dq.empty() && a[dq.back()] >= a[i])
        dq.pop_back();
    dq.push_back(i);
}

void dqPop(int i) {
    while (!dq.empty() && dq.front() <= i)
        dq.pop_front();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long sum = 0, sumMin = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    for(int i = 0; i < k; i++)
        dqPush(i);
    f[k - 1] = a[dq.front()];
    sumMin = max(sumMin, f[k - 1]);
    for(int i = k; i < n; i++) {
        dqPop(i - k);
        dqPush(i);
        //cout << i << " " << dq.front() << " " << a[dq.front()] << " " << f[i - k] << endl;
        f[i] = max(f[i - k] + a[dq.front()], f[i - 1]);
        sumMin = max(sumMin, f[i]);
    }
    //for(int i = 0; i < n; i++)
    //    cout << f[i] << " ";
    cout << sum - sumMin;
    return 0;
}