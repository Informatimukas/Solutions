#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int res = 0;
    while (cin >> s) {
        int mx = -1, cand = 0;
        for (auto& c : s) {
            int dig = c - '0';
            cand = max(cand, 10 * mx + dig);
            mx = max(mx, dig);
        }
        res += cand;
        cout << "res = " << res << endl;
    }
    return 0;
}