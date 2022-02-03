#include <bits/stdc++.h>

using namespace std;

int n, m;
stack < int > st;
set < int > num;

bool check(vector < int > num) {
    stack < int > st;
    int cnt = 0;
    num.push_back(n + 1);
    for(int i = 0; i < num.size(); i++) {
        while (st.size() && st.top() < num[i]) {
            cnt++;
            if (st.top() != cnt)
                return false;
            //cout << st.top() << " ";
            st.pop();
        }
        st.push(num[i]);
    }
    return true;
}

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        num.insert(i);
    vector < int > ans;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.push(x);
        ans.push_back(x);
        num.erase(num.find(x));
    }
    vector < int > temp;
    int cnt = 0;
    while (ans.size() != n) {
        stack < int > temp;
        for(set < int > :: iterator it = num.begin(); it != num.end(); ) {
            if (st.empty() || *it < st.top()) {
                temp.push(*it);
                it = num.erase(it);
            } else {
                break;
            }
        }
        while (temp.size()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        if (st.size()) 
            st.pop();
    }
    if (check(ans)) {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    } else 
        cout << "-1";
    return 0;
}