#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int st = 1000000050;
    int res = 0;
    string s;
    while (cin >> s) {
        int x = stoi(s.substr(1));
        cout << "old = " << st << endl;
        if (s[0] == 'L') {
            res += (st - 1) / mod - (st - x - 1) / mod;
            st -= x;
        } else {
            res += (st + x) / mod - st / mod;
            st += x;
        }
        cout << "new = " << st << endl;
        cout << "res = " << res << endl;
    }
    return 0;
}