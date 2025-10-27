#include <bits/stdc++.h>
using namespace std;

const string code = "><+-.,[]";
constexpr int mod = 1000003;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int res = 0;
    for (auto& ch : s)
        res = (16 * res + (code.find(ch) + 8)) % mod;
    cout << res << "\n";
    return 0;
}