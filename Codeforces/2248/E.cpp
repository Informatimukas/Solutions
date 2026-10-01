#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ill = pair<int, ll>;

bool Solve(int n, int d, const vector<ill>& seq) {
    if (seq.empty())
        return false;
    ll all = seq.back().second;
    for (auto& [k1, v1] : seq)
        for (auto& [k2, v2] : seq) {
            ll my = v1 + v2;
            ll k3 = k1 + k2 + 1;
            ll his = 0;
            while (k3 >= n) {
                his += all;
                k3 -= n;
            }
            auto it = distance(seq.begin(), ranges::lower_bound(seq, ill{k3 + 1, 0ll})) - 1;
            if (it >= 0)
                his += seq[it].second;
            if (my > his + d)
                return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, d;
        cin >> n >> m >> d;
        map<int, ll> M;
        for (int i = 0; i < m; i++) {
            int p, r;
            cin >> p >> r;
            M[p] += r;
        }
        vector<ill> seq;
        ll cur = 0;
        for (auto& [k, v] : M) {
            cur += v;
            seq.emplace_back(k, cur);
        }
        cout << (Solve(n, d, seq) ? "YES" : "NO") << "\n";
    }
    return 0;
}
