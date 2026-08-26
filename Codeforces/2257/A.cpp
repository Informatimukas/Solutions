#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        array<bool, Maxl> has{};
        while (n--) {
            string s;
            cin >> s;
            has[s[0] - 'a'] = true;
        }
        bool ok = true;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            bool cur = true;
            for (auto ch : s)
                if (!has[ch - 'A']) {
                    cur = false;
                    break;
                }
            if (!cur)
                ok = false;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
