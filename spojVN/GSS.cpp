#include <bits/stdc++.h>
#define left first.first
#define right first.second
#define sum second.first
#define ans second.second
#define maxn 50001
#define oo 1000000001
using namespace std;

long long n,a[maxn],m;
typedef pair < long long , long long > II;
typedef pair < II , II > IIII;
IIII t[4*maxn];
void doc()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
}
void khoitao(int l,int r,int k)
{
    if(l==r)
    {
        t[k]=IIII(II(a[l],a[l]),II(a[l],a[l]));
        return;
    }
    int mid=(l+r)/2;
    khoitao(l,mid,k*2);
    khoitao(mid+1,r,k*2+1);
    t[k].sum=t[2*k].sum+t[2*k+1].sum;
    t[k].left=max(t[2*k].left,t[2*k].sum+t[2*k+1].left);
    t[k].right=max(t[2*k+1].right,t[2*k+1].sum+t[2*k].right);
    t[k].ans=max(max(t[2*k].ans,t[2*k+1].ans),t[2*k].right+t[2*k+1].left);
}
IIII get(int a,int b,int l,int r,int k)
{
    if(r<a || l>b)
        return IIII(II(0,-oo),II(-oo,-oo));
    if(a<=l && r<=b)
        return t[k];
    int mid=(l+r)/2;
    IIII s1=get(a,b,l,mid,k*2);
    IIII s2=get(a,b,mid+1,r,k*2+1);
    long long lefs1=max(s1.left,s1.sum+s2.left);
    long long righs1=max(s2.right,s2.sum+s1.right);
    long long ans1=max(max(s1.ans,s2.ans),s1.right+s2.left);
    long long sum1=s1.sum+s2.sum;
    return IIII(II(lefs1,righs1),II(sum1,ans1));
}
void tinh()
{
    khoitao(1,n,1);
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<get(u,v,1,n,1).ans<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    doc();
    tinh();
}
