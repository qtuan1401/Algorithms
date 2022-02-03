#include <bits/stdc++.h>
using namespace std;
struct trie {
	int len, d;
	trie* next[3];
	trie() {
		len = 0;
		d = 0;
		for(int i=0;i<2;i++)
			next[i] = NULL;
	}
};
trie* root = new trie();
void add(int n) {
	trie* node = root;
	for(int i=1;i<=n;i++) {
		int x;
		scanf("%d", &x);
		node -> d++;
		if (node -> next[x] == NULL) {
			node -> next[x] = new trie();
			//node -> next[x] -> len = node -> len;
		}
		node = node -> next[x];
		//cout << x << " " << node -> d << " " << node -> len << endl;
	}
	node -> len++;
}
trie* node;
int n, q, m, k, res;
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &q);
	for(int i=1;i<=n;i++)
		scanf("%d", &m), add(m);
	while (q--) {
		scanf("%d", &k);
		int i;
		node = root;
		res = 0;
		for(i=1;i<=k;i++) {
			int x;
			scanf("%d", &x);
			node = node -> next[x];
			if (node == NULL)	
				break;
			res += node -> len;
		}
		if (node != NULL)
			res += node -> d;
		for(int j=i+1;j<=k;j++)
			scanf("%d", &i);
		printf("%d\n", res);
	}
	return 0;
}