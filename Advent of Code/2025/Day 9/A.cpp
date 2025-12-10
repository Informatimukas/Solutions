#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<llll> a;
    string s;
    while (getline(cin, s)) {
        s[s.find(',')] = ' ';
        stringstream ss(s);
        ll x, y;
        ss >> x >> y;
        a.emplace_back(x, y);
    }
    ll res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            res = max(res, (abs(a[i].first - a[j].first) + 1) *
            (abs(a[i].second - a[j].second) + 1));
    cout << res << "\n";
    return 0;
}