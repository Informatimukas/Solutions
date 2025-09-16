#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int mod = 1000000007;

struct tree {
    vector<vector<int>> neigh;
    vector<int> cnt;
    map<ii, int> M;
    int getId(const ii& v) {
        auto it = M.find(v);
        if (it != M.end())
            return it->second;
        int cur = cnt.size();
        neigh.push_back({});
        cnt.push_back(0);
        M.emplace(v, cur);
        return cur;
    }
};

array<int, 2> Solve(tree& t, int v, int p) {
    array<int, 2> dp{};
    dp[0] = 1;
    for (auto& u : t.neigh[v]) {
        if (u == p) continue;
        auto got = Solve(t, u, v);
        dp[1] = static_cast<ll>(dp[1]) * got[0] % mod;
        dp[1] = (dp[1] + static_cast<ll>(dp[0]) * got[1]) % mod;
        dp[0] = static_cast<ll>(dp[0]) * got[0] % mod;
    }
    array<int, 2> res{};
    if (t.cnt[v] == 0)
        res[0] = dp[0];
    if (t.cnt[v] == 1)
        res[1] = dp[0];
    else if (t.cnt[v] == 0)
        res[1] = (dp[0] + dp[1]) % mod;
    cout << "solve " << v << " " << p << ": " << res[0] << " " << res[1] << endl;
    t.cnt[v] = -1;
    return res;
}

int Solve(const vector<ii>& seq) {
    tree t;
    for (int i = 0; i + 1 < seq.size(); i++) {
        if ((seq[i].first + seq[i].second) % 2 != (seq[i + 1].first + seq[i + 1].second) % 2)
            return 0;
        int d = abs(seq[i].first - seq[i + 1].first) +
            abs(seq[i].second - seq[i + 1].second);
        if (d != 2) return 0;
        if (seq[i].first == seq[i + 1].first) {
            int v = t.getId({seq[i].first, (seq[i].second + seq[i + 1].second) / 2});
            t.cnt[v]++;
        } else if (seq[i].second == seq[i + 1].second) {
            int v = t.getId({(seq[i].first + seq[i + 1].first) / 2, seq[i].second});
            t.cnt[v]++;
        } else {
            int u = t.getId({seq[i].first, seq[i + 1].second});
            int v = t.getId({seq[i + 1].first, seq[i].second});
            cout << "u = " << u << " v = " << v << endl;
            t.neigh[u].push_back(v);
            t.neigh[v].push_back(u);
        }
    }
    cout << "constructed " << t.cnt.size() << endl;
    int res = 1;
    for (int i = 0; i < t.cnt.size(); i++)
        if (t.cnt[i] != -1) {
            auto got = Solve(t, i, -1);
            res = static_cast<ll>(res) * got[1] % mod;
        }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<ii> seq(k + 1);
        for (auto& [a, b] : seq)
            cin >> a >> b;
        cout << Solve(seq) << "\n";
    }
    return 0;
}
