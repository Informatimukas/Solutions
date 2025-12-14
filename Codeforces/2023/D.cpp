// Next steps: the solution below works well when p is the same. It gets a TLE in
// a general case. Maybe it's worth to think about how to combine solutions
// across different p. Probably handle 98 and 99 separately.
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ii = pair<int, int>;
using ldld = pair<ld, ld>;

constexpr ld eps = 1e-6l;

bool Less(const ldld& a, const ldld& b) {
    if (fabs(a.first - b.first) < eps)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<ld, ld, greater<>> M;
    vector<ii> a;
    ld sum100 = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, w;
        cin >> p >> w;
        if (p == 100)
            sum100 += w;
        else a.emplace_back(p, w);
    }
    ranges::sort(a);
    vector<ldld> seq = {{1, sum100}};
    for (auto& [p, w] : a) {
        ld prob = p / 100.0l;
        ld value = prob * w;
        vector<ldld> oth(seq.size());
        for (int i = 0; i < seq.size(); i++) {
            auto& [fir, sec] = seq[i];
            ld key = prob * fir;
            ld val = prob * sec + fir * value;
            oth[i] = {key, val};
        }
        vector<ldld> res;
        res.reserve(2 * seq.size());
        ld mx = -1;
        int i = 0, j = 0;
        while (i < seq.size() || j < oth.size())
            if (i < seq.size() && (j >= oth.size() || Less(seq[i], oth[j]))) {
                if (seq[i].second > mx + eps) {
                    mx = seq[i].second;
                    res.push_back(seq[i]);
                }
                ++i;
            } else {
                if (oth[j].second > mx + eps) {
                    mx = oth[j].second;
                    res.push_back(oth[j]);
                }
                ++j;
            }
        seq = std::move(res);
    }
    cout << fixed << setprecision(10) << seq.back().second << "\n";
    return 0;
}
