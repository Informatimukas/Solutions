#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int st = 50;
    int res = 0;
    string s;
    while (cin >> s) {
        int x = stoi(s.substr(1));
        if (s[0] == 'L')
            st = (st - x % mod + mod) % mod;
        else st = (st + x) % mod;
        res += st == 0;
        cout << "res = " << res << endl;
    }
    return 0;
}