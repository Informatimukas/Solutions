#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using iill = pair<ii, ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> V(n);
    for (auto& p : V)
        cin >> p.first >> p.second;
    ranges::sort(V);
    map<ii, int> M;
    map<iill, int> M2;
    ll res = 0;
    for (int i = 0; i < V.size(); i++)
        for (int j = i + 1; j < V.size(); j++) {
            int dx = V[j].first - V[i].first;
            int dy = V[j].second - V[i].second;
            ll dist = static_cast<ll>(dx) * dx + static_cast<ll>(dy) * dy;
            int g = __gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            res += 2 * M[{dx, dy}]++;
            res -= M2[{{dx, dy}, dist}]++;
        }
    cout << res / 2 << "\n";
    return 0;
}
