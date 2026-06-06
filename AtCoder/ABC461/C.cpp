#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<ii> seq(n);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    ranges::sort(seq, greater(), [](auto&& x) { return x.second; });
    set<int> S;
    int allowed = k - m;
    ll res = 0;
    for (auto& [c, v] : seq)
        if ((S.insert(c).second || allowed-- > 0) && k-- > 0)
            res += v;
    cout << res << "\n";
    return 0;
}
