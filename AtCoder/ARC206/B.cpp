#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    vector<int> c(n);
    for (auto& x : c)
        cin >> x;
    vector seq(n + 1, vector<int>());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += c[i];
        auto ind = distance(seq[c[i]].begin(), ranges::lower_bound(seq[c[i]], p[i]));
        if (ind < seq[c[i]].size())
            seq[c[i]][ind] = p[i];
        else seq[c[i]].push_back(p[i]);
    }
    for (int i = 1; i < seq.size(); i++)
        res -= static_cast<ll>(i) * seq[i].size();
    cout << res << "\n";
    return 0;
}