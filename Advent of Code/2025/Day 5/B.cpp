#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<ii> seq;
    string s;
    while (cin >> s) {
        if (s == "end")
            break;
        s[s.find('-')] = ' ';
        stringstream ss(s);
        ll a, b;
        ss >> a >> b;
        seq.emplace_back(a, b);
    }
    ranges::sort(seq);
    vector<ii> res;
    for (auto& [a, b] : seq)
        if (res.empty() || res.back().second + 1 < a)
            res.emplace_back(a, b);
        else res.back().second = max(res.back().second, b);
    ll ans = 0;
    for (auto& [a, b]: res)
        ans += b - a + 1;
    cout << ans << endl;
    return 0;
}
