#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    ll a;
    cin >> a;
    map<ll, ll, greater<>> M;
    M.emplace(a - 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> a;
        while (M.begin()->first >= a) {
            auto p = *M.begin();
            M.erase(M.begin());
            ll tk = p.first / a;
            M[p.first % a] = max(M[p.first % a], p.second + tk * a * i);
            M[a - 1] = max(M[a - 1], p.second + (tk - 1) * a * i);
        }
    }
    ll res = 0;
    for (auto& [fir, sec] : M)
        res = max(res, sec + fir * n);
    cout << res << "\n";
    return 0;
}