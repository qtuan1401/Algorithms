#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e3 + 10;
const int MXM = 1e3 + 10;

int n, m;
int bit[MXN][MXM][5];
map < string, int > mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    mp["?"] = -1;
    for(int i = 0; i < n; i++) {
        string s, t, s1, op, s2;
        cin >> s >> t >> s1;
        mp[s] = i;
        if (s1[0] == '0' || s1[0] == '1') {
            for(int j = 0; j < m; j++)
                bit[i][j][0] = bit[i][j][1] = s1[j] - '0';
        } else {
            cin >> op >> s2;
            int i1 = mp[s1], i2 = mp[s2];
            for(int j = 0; j < m; j++) {
                for(int b1 = 0; b1 < 2; b1++) {
                    for(int b2 = 0; b2 < 2; b2++) { 
                        if (s1 == "?" && s2 == "?") {
                            if (b1 != b2)
                                continue;
                            if (op == "AND" || op == "OR")
                                bit[i][j][b1] = b1;
                            else 
                                bit[i][j][b1] = 0; 
                        } else if (s1 == "?" && s2 != "?") {
                            if (op == "XOR")
                                bit[i][j][b1] = b1 ^ bit[i2][j][b1];
                            else if (op == "OR")
                                bit[i][j][b1] = b1 | bit[i2][j][b1];
                            else
                                bit[i][j][b1] = b1 & bit[i2][j][b1];
                        } else if (s1 != "?" && s2 == "?") {
                            if (op == "XOR")
                                bit[i][j][b2] = b2 ^ bit[i1][j][b2];  
                            else if (op == "OR")
                                bit[i][j][b2] = b2 | bit[i1][j][b2];
                            else
                                bit[i][j][b2] = b2 & bit[i1][j][b2];
                        } else {
                            if (op == "XOR") {
                                bit[i][j][b1] = bit[i1][j][b1] ^ bit[i2][j][b1];
                                bit[i][j][b2] = bit[i1][j][b2] ^ bit[i2][j][b2];
                            } else if (op == "OR") {
                                bit[i][j][b1] = bit[i1][j][b1] | bit[i2][j][b1];
                                bit[i][j][b2] = bit[i1][j][b2] | bit[i2][j][b2];
                            } else {
                                bit[i][j][b1] = bit[i1][j][b1] & bit[i2][j][b1];
                                bit[i][j][b2] = bit[i1][j][b2] & bit[i2][j][b2];
                            }
                        }
                    }
                }
            }
        }
    }

    string rMax = "", rMin = "";
    for(int j = 0; j < m; j++) {
        int r0 = 0, r1 = 0;
        for(int i = 0; i < n; i++) {
            r0 += bit[i][j][0];
            r1 += bit[i][j][1];
        }
        if (r0 >= r1)
            rMax += "0";
        else 
            rMax += "1";
        if (r0 <= r1)
            rMin += "0";
        else 
            rMin += "1";
    }
    cout << rMin << "\n" << rMax;
    return 0;
}