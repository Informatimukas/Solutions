// Next steps: debug the written solution (it might be just efficient enough);
// Need to test pos struct by changing Maxb first.
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ull = unsigned long long;

constexpr int Inf = 1000000007;
constexpr int Maxb = 64;

struct pos {
    vector<ull> bits;
    vector<ii> seq;
    int best{Inf};
    pos(vector<ii>&& seq): bits((seq.size() + Maxb - 1) / Maxb), seq(std::move(seq)) {}
    void Set(int ind) {
        int a = ind / Maxb, b = ind % Maxb;
        bits[a] |= static_cast<ull>(1) << b;
        ull rem = bits[a] >> (b + 1);
        if (rem) {
            int oind = __builtin_ctzll(rem) + 1 + ind;
            best = min(best, seq[oind].first - seq[ind].first);
        } else for (int i = a + 1; i < bits.size(); i++)
            if (bits[i]) {
                int oind = i * Maxb + __builtin_ctzll(bits[i]);
                best = min(best, seq[oind].first - seq[ind].first);
                break;
            }
        rem = bits[a] & ((static_cast<ull>(1) << b) - 1);
        if (rem) {
            int oind = (a + 1) * Maxb - 1 - __builtin_clzll(rem);
            best = min(best, seq[ind].first - seq[oind].first);
        } else for (int i = a - 1; i >= 0; i--)
            if (bits[i]) {
                int oind = (i + 1) * Maxb - 1 - __builtin_clzll(bits[i]);
                best = min(best, seq[ind].first - seq[oind].first);
                break;
            }
    }
    void Unset(int ind) {
        int a = ind / Maxb, b = ind % Maxb;
        bits[a] ^= static_cast<ull>(1) << b;
    }
};

vector<ii> getRange(int l, int r, const vector<int>& a, vector<int>& inplace) {
    vector<ii> res(r - l + 1);
    for (int i = l; i <= r; i++)
        res[i - l] = {a[i], i};
    ranges::sort(res);
    for (int i = 0; i < res.size(); i++)
        inplace[res[i].second] = i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), inplace(n);
    for (auto& x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<ii> queries(m);
    vector<int> res(m);
    int p = sqrt(n) + 2;
    vector queriesByPart(n / p + 2, vector<ii>());
    for (int i = 0; i < m; i++) {
        auto& [u, v] = queries[i];
        cin >> u >> v;
        u--;
        v--;
        if (v - u <= p) {
            auto seq = getRange(u, v, a, inplace);
            pos state(std::move(seq));
            for (int j = u; j <= v; j++)
                state.Set(inplace[j]);
            res[i] = state.best;
        } else queriesByPart[u / p + 1].emplace_back(v, i);
    }
    vector<int> leftValue(n);
    for (int i = 0; i < queriesByPart.size(); i++) {
        auto& seq = queriesByPart[i];
        if (seq.empty())
            continue;
        int R = i * p, L = i * p;
        ranges::sort(seq);
        int from = (i - 1) * p, to = min((i + 1) * p, n) - 1;
        auto got = getRange(from, to, a, inplace);
        pos state(std::move(got));
        for (auto& [rig, ind] : seq) {
            while (R <= rig)
                state.Set(inplace[R++]);
            int memBest = state.best;
            auto& ans = res[ind];
            for (int j = L - 1; j >= queries[ind].first; j--)
                state.Set(inplace[j]);
            res[ind] = state.best;
            state.best = memBest;
            for (int j = L - 1; j >= queries[ind].first; j--)
                state.Unset(inplace[j]);
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
    return 0;
}
