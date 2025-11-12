// Next steps: debug the solution using generated tests and correctSolve.
// The idea is to brute force the minimum u value and then pick p optimally;
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ii = pair<int, int>;

constexpr int mult = 1000;

int readInt() {
    ld res;
    cin >> res;
    return static_cast<int>(res * mult + 1e-5);
}

int correctSolve(int lvl, const vector<ii>& pu, int a, int b, int best) {
    if (lvl >= pu.size())
        return best;
    int res = correctSolve(lvl + 1, pu, a, b, best);
    auto& [p, u] = pu[lvl];
    if (a > 0)
        res = max(res, correctSolve(lvl + 1, pu, a - 1, b, best + mult * p));
    if (b > 0)
        res = max(res, correctSolve(lvl + 1, pu, a, b - 1, best + mult * u));
    if (a > 0 && b > 0)
        res = max(res, correctSolve(lvl + 1, pu, a - 1, b - 1, best + mult * (p + u) - p * u));
    return res;
}

int Solve(const ii& lim, const vector<ii>& pu, int a, int b) {
    vector<int> diffs, best;
    int cur = 0;
    for (int i = 0; i < pu.size(); i++) {
        auto& [p, u] = pu[i];
        int cand = u * (mult - p);
        if (ii{cand, i} >= lim) {
            cur += mult * u;
            b--;
            best.push_back(p * (mult - u));
        } else if (ii{mult * u, i} >= lim) {
            cur += mult * u;
            diffs.push_back(mult * (p - u));
        } else best.push_back(mult * p);
    }
    if (b < 0 || a + b < diffs.size() || b > diffs.size())
        return 0;
    ranges::sort(diffs, greater());
    int tk = diffs.size() - b;
    for (int i = 0; i < tk; i++)
        cur += diffs[i];
    a -= tk;
    ranges::sort(best, greater());
    for (int i = 0; i < a; i++)
        cur += best[i];
    return cur;
}

int Solve(vector<ii> pu, int n, int a, int b) {
    vector<ii> seq;
    ranges::sort(pu);
    for (int i = 0; i < n; i++) {
        auto& [p, u] = pu[i];
        seq.emplace_back(mult * u, i);
        if (p)
            seq.emplace_back((mult - p) * u, i);
    }
    seq.emplace_back(mult * mult * mult, 0);
    int res = 0;
    for (auto& lim : seq)
        res = max(res, Solve(lim, pu, a, b));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ii> pu(n);
    for (auto& x : pu | views::keys)
        x = readInt();
    for (auto& x : pu | views::values)
        x = readInt();
    cout << fixed << setprecision(10) <<
        Solve(pu, n, a, b) / static_cast<ld>(mult * mult) << "\n";
    return 0;
}
