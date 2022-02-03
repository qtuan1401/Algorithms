#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "test";
// Số test kiểm tra
const int NTEST = 1000000;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rand() * 1LL * rand() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".in").c_str());
        int n = Rand(1, 10);
        vector < int > num(n);
        for (int i = 0; i < n; i++)
            num[i] = i + 1;
        random_shuffle(num.begin(), num.end());
        inp << "1\n" << num.size() << '\n';
        for (int i = 0; i < n; i++)
            inp << num[i] << " ";
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        const string ss = "./a", cc = "./a1";
        system(ss.c_str());
        system(cc.c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}