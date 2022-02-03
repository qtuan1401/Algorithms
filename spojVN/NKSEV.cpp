#include <bits/stdc++.h>
using namespace std;
const int mod = 1337377;
struct trie {
	trie* next[30];
	int pos;
	trie() {
		for(int i=0;i<25;i++)
			next[i] = NULL;
		pos = 0;
	} 
};
trie* root = new trie();
void add(char s[]) {
	int n = strlen(s);
	trie* node = root;
	for(int i=0;i<n;i++) {
		int c = s[i] - 'a';
		if (node -> next[c] == NULL) 
			node -> next[c] = new trie();
		node = node -> next[c];
	}
	node -> pos++;
}
int n;
char s[int(3e5) + 5], s1[4005];
long long f[int(3e5) + 5];
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%s", s);
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%s", s1);
		//cout << s1 << endl;
		add(s1);
	}	
	n = strlen(s);
	f[n] = 1; 
	for(int i=n - 1;i>=0;i--) {
		//cout << i << endl;
		int j = i;
		trie* node = root;
		while (true) {
			//cout << node -> next[c] << endl;
			if (j >= n)
				break;
			node = node -> next[s[j] - 'a'];
			j++;
			if (node == NULL)
				break;
			if (node -> pos)
				f[i] = (f[i] + f[j]) % mod;
		}
		//cout << endl;
	}
	printf("%lld", f[0]);
	return 0;
}