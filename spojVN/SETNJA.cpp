#include <bits/stdc++.h>

using namespace std;

char s[100005];

struct solve {
   vector< int > digits;

   solve(int x) {
      digits.push_back(x);
   }

   void print() {
      int n = digits.size();
      printf("%d", digits[--n]);
      while (n > 0) printf("%09d", digits[--n]);
   }

   void operator += (const solve &b) {
      int carry = 0;
      for(int i = 0;i < digits.size() || i < b.digits.size() || carry; ++i) {
         int x = carry;
         if (i < digits.size()) x += digits[i];
         if (i < b.digits.size()) x += b.digits[i];
         carry = x >= 1000000000;
         if (carry) x -= 1000000000;
         if( i < digits.size() ) digits[i] = x;
         else digits.push_back( x );
      }
   }
};

int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%s", s);
    solve resa(1), resb(0);
	for(int i=strlen(s)-1;i>=0;i--) {
        solve a(0), b(0);
        if (s[i] == '*' || s[i] == 'P') {
			a += resa;
			b += resb;
		}
		if (s[i] == '*' || s[i] == 'L') {
			a += resa;
			a += resa;
			b += resb;
		}
		if  (s[i] == '*' || s[i] == 'R') {
			a += resa;
			a += resa;
			b += resb;
			b += resa;
		}

		resa = a;
		resb = b;
	}

	resa += resb;
	resa.print();
}
