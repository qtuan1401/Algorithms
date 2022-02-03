 #include <bits/stdc++.h>

using namespace std;
unsigned long long int n,i,maxb,maxa,Counta,Countb,t;
int main()
{
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> Counta >> Countb >> maxa >> maxb;
        if (maxa==0) Counta=0;
        if (maxb==0) Countb=0;
        if (Counta>Countb)
        {
            Counta=Counta ^ Countb;
            Countb=Counta ^ Countb;
            Counta=Counta ^ Countb;
            maxa=maxa ^ maxb;
            maxb=maxa ^ maxb;
            maxa=maxa ^ maxb;
        }
        cout << Counta+min(Countb,(Counta+1)*maxb) << endl;
    }
    return 0;
}
