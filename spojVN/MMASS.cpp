#include <bits/stdc++.h>
using namespace std;
string s;
int n;
stack<int> Stack;
int calc(char c)
{
    if (c=='C') return 12;
    else if (c=='H') return 1;
    else if (c=='O') return 16;
    return 0;
}
main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    n=s.length();
    int  val=0;
    for(int i=0;i<n;i++)
    {
        if (isdigit(s[i]))
        {
            val=Stack.top();
            Stack.pop();
            Stack.push(val*(s[i]-'0'));
        }
        if (s[i]=='(') Stack.push(-1);
        if (s[i]==')')
        {
            val=0;
            while (!Stack.empty() && Stack.top()!=-1)
            {
                val+=Stack.top();
                Stack.pop();
            }
            Stack.pop();
            Stack.push(val);
        }
        else if (isalpha(s[i])) Stack.push(calc(s[i]));
    }
    val=0;
    while (!Stack.empty())
    {
        val+=Stack.top();
        Stack.pop();
    }
    cout << val;
}
