#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 100000000000000000ll;
constexpr int Maxl = 12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    ll res = 0;
    while (cin >> s) {
        vector mx(Maxl + 1, -Inf);
        mx[0] = 0;
        for (auto& c : s) {
            int dig = c - '0';
            for (int j = Maxl - 1; j >= 0; j--)
                mx[j + 1] = max(mx[j + 1], 10 * mx[j] + dig);
        }
        res += mx[Maxl];
        cout << "res = " << res << endl;
    }
    return 0;
}