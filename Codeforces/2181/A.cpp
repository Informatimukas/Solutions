#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxl = 26;

ll Solve(const string& s, int m, array<ll, Maxl>& has) {
    array<ll, Maxl> my{};
    for (auto ch : s)
        ++my[ch - 'A'];
    ll res = 1000000000000000000ll;
    for (int i = 0; i < Maxl; i++) {
        ll lft = has[i] - my[i];
        ll tot = lft * m;
        if (tot < my[i])
            return -1;
        if (lft > 0)
            res = min(res, (tot - my[i]) / lft);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    array<ll, Maxl> has{};
    vector<string> s(n);
    for (auto& x : s) {
        cin >> x;
        for (auto ch : x)
            ++has[ch - 'A'];
    }
    for (int i = 0; i < n; i++)
        cout << Solve(s[i], m, has) << (i + 1 < n ? ' ' : '\n');
    return 0;
}
