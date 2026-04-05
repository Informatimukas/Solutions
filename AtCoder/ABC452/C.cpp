#include <bits/stdc++.h>
using namespace std;

constexpr int Maxs = 10;
constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int m;
    cin >> m;
    vector<string> s(m);
    for (auto& x : s)
        cin >> x;
    int mn = 0;
    vector good(Maxs, (1 << Maxl) - 1);
    for (int i = 0; i < n; i++) {
        int allowed = 0;
        for (int j = 0; j < m; j++)
            if (a[i] == s[j].length())
                allowed |= 1 << (s[j][b[i] - 1] - 'a');
        good[i] &= allowed;
        mn = max(mn, b[i] + 1);
    }
    for (int i = 0; i < m; i++)
        if (s[i].length() == n) {
            bool ok = true;
            for (int j = 0; j < s[i].length(); j++)
                if (!(good[j] & 1 << (s[i][j] - 'a'))) {
                    ok = false;
                    break;
                }
            cout << (ok ? "Yes" : "No") << "\n";
        } else cout << "No\n";
    return 0;
}
