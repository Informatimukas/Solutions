#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> R(n);
    for (auto& x : R)
        cin >> x;
    int l = 0, r = n - 1;
    while (s[l] == '#')
        l++;
    while (s[r] == '#')
        r--;
    vector<ii> seq;
    for (int i = l, j; i <= r; i = j) {
        j = i;
        int mx = 0, cnt = 0;
        while (j <= r && s[i] == s[j]) {
            if (R[j] > mx) {
                mx = R[j];
                cnt = 0;
            }
            if (R[j] == mx)
                cnt++;
            j++;
        }
        seq.emplace_back(mx, cnt);
    }
    int mx = 0;
    for (int i = 0; i < seq.size(); i++)
        mx = max(mx, seq[i].first);
    ll res = 0;
    for (int i = 0; i + 2 < seq.size(); i += 2) {
        ll ways = static_cast<ll>(seq[i].second) * seq[i + 2].second;
        if (seq[i].first == mx || seq[i + 2].first == mx || seq[i + 1].first == mx)
            res += ways;
    }
    cout << res << "\n";
    return 0;
}
