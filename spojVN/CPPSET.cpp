#include <bits/stdc++.h>
using namespace std;
set<int> s;
set<int>::iterator it;
int n,x;
main()
{
	//freopen("test.inp","r",stdin);
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		else if (n==1)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		else if (n==2)
		{
			scanf("%d",&x);
			s.erase(x);
		}
		else if (n==3)
		{
			if (s.empty())
				printf("empty\n");
			else printf("%d\n",*(s.begin()));
		}
		else if (n==4)
		{
			if (s.empty())
				printf("empty\n");
			else printf("%d\n",*(s.rbegin()));
		}
		else if (n==5)
		{
			scanf("%d",&x);
			if (s.empty())
				printf("empty\n");
			else
			{
				it=s.upper_bound(x);
				if (it==s.end())
					printf("no\n");
				else
					printf("%d\n",*it);
			}
		}
		else if (n==6)
		{
			scanf("%d",&x);
			if (s.empty())
				printf("empty\n");
			else
			{
				it=s.lower_bound(x);
				if (it==s.end())
					printf("no\n");
				else
					printf("%d\n",*it);
			}
		}
		else if (n==7)
		{
			scanf("%d",&x);
			if (s.empty())
				printf("empty\n");
			else
			{
				it=s.lower_bound(x);
				if (it==s.begin())
					printf("no\n");
				else
					printf("%d\n",*(--it));
			}
		}
		else if (n==8)
		{
			scanf("%d",&x);
			if (s.empty())
				printf("empty\n");
			else
			{
				it=s.upper_bound(x);
				if (it==s.begin())
					printf("no\n");
				else if (*it==x)
					printf("%d\n",x);
				else
					printf("%d\n",*(--it));
			}
		}
	}
}
