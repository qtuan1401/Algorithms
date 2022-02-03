#include <bits/stdc++.h>
#define forr(i,a,b) for(long i=(a);i<=(b);i++)
#define forl(i,a,b) for(long i=(b);i>=(a);i--)
using namespace std;
#define fi ""
#define fo ""
#define st first
#define nd second
#define Memset(a,x) memset(a,x,sizeof(a))
typedef long long int lli;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef unsigned long long int ulli;
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
   return res;
}
string dp[1000][1000];
main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    string s;
    cin >> s;
   // cout << s << endl;
    int n=s.size();
    s="#"+s;
    forr(i,0,n)
        forr(j,0,n) dp[i][j]="0";
    //forr(i,2,n) dp[i][i-1]="0";
    forr(i,1,n) dp[i][i]="1";
    forr(k,1,n-1)
        forr(i,1,n-k)
        {
            long j=i+k;
            if (s[i]==s[j]) dp[i][j]=add(add(dp[i+1][j],dp[i][j-1]),"1");
            else dp[i][j]=sub(add(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]);
        }
    //forr(i,1,n)
    //{
      //  forr(j,1,n) cout << dp[i][j] <<  " ";
        //cout << endl;
   // }
    cout << dp[1][n];
    //cout << add("4","5");
    //cout << sub("3","2");
}

