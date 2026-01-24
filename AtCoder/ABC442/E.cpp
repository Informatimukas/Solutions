#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ld = long double;
using ldii = pair<ld, ii>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ii> p(n + 1);
    vector<ldii> seq;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        int g = __gcd(abs(p[i].first), abs(p[i].second));
        p[i].first /= g;
        p[i].second /= g;
        seq.emplace_back(atan2(static_cast<ld>(p[i].second), static_cast<ld>(p[i].first)), p[i]);
    }
    ranges::sort(seq);
    while (q--) {
        int a, b;
        cin >> a >> b;
        ldii lef = {atan2(static_cast<ld>(p[b].second), static_cast<ld>(p[b].first)), p[b]};
        ldii rig = {atan2(static_cast<ld>(p[a].second), static_cast<ld>(p[a].first)), p[a]};
        int lind = distance(seq.begin(), ranges::lower_bound(seq, lef));
        int rind = distance(seq.begin(), ranges::upper_bound(seq, rig));
        int siz = rind - lind;
        if (siz <= 0)
            siz += seq.size();
        cout << siz << "\n";
    }
    return 0;
}
