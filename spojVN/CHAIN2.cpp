#include <bits/stdc++.h>
using namespace std;
struct trie {
	int len;
	trie* next[30];
	trie() {
		for(int i=0;i<=25;i++)
			next[i] = NULL;
		len = 0;
	}
};
trie* root= new trie;
string s;
int n, res;
void add(string s) {
	trie* node = root;
	for(int i=0;i<s.size();i++) {
		int c = s[i] - 'a';
		if (node -> next[c] == NULL) {
			node -> next[c] = new trie();
			node -> next[c] -> len = node -> len;
		}
		res = max(res, node -> len);
		node = node -> next[c];
	}
	res = max(res, ++(node -> len));
}
int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> s;
		add(s);
	}
	cout << res;
	return 0;
}