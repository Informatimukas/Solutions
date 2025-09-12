#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        array<int, 2> c;
        int h;
        cin >> n >> c[0] >> c[1] >> h;
        c[1] = min(c[1], c[0] + h);
        c[0] = min(c[0], c[1] + h);
        string s;
        cin >> s;
        int res = 0;
        for (auto& ch : s)
            res += c[ch - '0'];
        cout << res << "\n";
    }
    return 0;
}