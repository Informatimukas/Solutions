#include <bits/stdc++.h>
using namespace std;

bool getOdd(int lef, int rig) {
    if (lef > rig)
        return false;
    cout << "? " << lef + 1 << " " << rig + 1 << endl;
    int res;
    cin >> res;
    return (rig - lef + 1) / res % 2;
}

bool Answer(const string& s) {
    cout << "! " << s << endl;
    int res;
    cin >> res;
    return res == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mem = n;
        if (n % 2)
            n--;
        vector dif(n, false);
        bool all = getOdd(0, n - 1);
        bool L = false, R = false;
        int lef = 0, rig = n - 2;
        for (int i = 0; i < n / 2; i++)
            if (i % 2 == 0) {
                bool my = all ^ L ^ getOdd(lef + 2, n - 1);
                dif[lef + 1] = my;
                L ^= my;
                lef += 2;
            } else {
                bool my = all ^ R ^ getOdd(0, rig - 1);
                dif[rig + 1] = my;
                R ^= my;
                rig -= 2;
            }
        if (n > 2) {
            bool my = all ^ getOdd(1, n - 2);
            dif[n - 2] = dif[n - 1] ^ my;
            dif[n - 1] = my;
            L = dif[0] ^ dif[1];
            R = dif[n - 2] ^ dif[n - 1];
            lef = 2, rig = n - 4;
            for (int i = 0; i < n / 2 - 2; i++)
                if (i % 2 == 0) {
                    bool my = all ^ L ^ getOdd(lef + 1, n - 2);
                    dif[lef] = dif[lef] ^ my ^ dif[n - 1];
                    dif[lef + 1] = dif[lef + 1] ^ my ^ dif[n - 1];
                    L ^= dif[lef] ^ dif[lef + 1];
                    lef += 2;
                } else {
                    bool my = all ^ R ^ getOdd(1, rig);
                    dif[rig] = dif[rig + 1] ^ my;
                    dif[rig + 1] = my;
                    R ^= dif[rig] ^ dif[rig + 1];
                    rig -= 2;
                }
        }
        if (mem > n) {
            n++;
            dif[n - 1] = dif[n - 2] ^ getOdd(n - 2, n - 1);
        }
        string res1(n, '0'), res2(n, '1');
        for (int i = 0; i < n; i++)
            if (dif[i]) {
                res1[i] = '1';
                res2[i] = '0';
            }
        if (!Answer(res1))
            Answer(res2);
    }
    return 0;
}
