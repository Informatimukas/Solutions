#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

ll Solve(const vector<int>& a) {
    map<int, llll> M;
    ll res = 0;
    for (auto& x : a) {
        if (x % 3 == 0)
            ++M[x / 3].first;
        if (x % 7 == 0)
            ++M[x / 7].second;
        if (x % 5 == 0) {
            auto got = M[x / 5];
            res += got.first * got.second;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ll res = Solve(a);
    ranges::reverse(a);
    res += Solve(a);
    cout << res << "\n";
    return 0;
}
