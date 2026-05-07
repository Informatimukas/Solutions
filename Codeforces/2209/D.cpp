#include <bits/stdc++.h>
using namespace std;

using ic = pair<int, char>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int r, g, b;
        cin >> r >> g >> b;
        vector<ic> seq = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
        ranges::sort(seq);
        int sum = accumulate(seq.begin(), seq.end(), 0, [](auto&& a, auto&& b) {
            return a + b.first;
        });
        int p = min(sum / 2, sum - seq[2].first);
        string res;
        array<array<int, 3>, 3> cnt{};
        if (sum > 2 * p) {
            res += seq[2].second;
            seq[2].first--;
        }
        for (int i = 0; i < p; i++) {
            auto ind = distance(seq.begin(),
                ranges::min_element(seq, {}, [](auto&& a) {
                return a.first;
            }));
            vector<int> rem;
            for (int j = 0; j < seq.size(); j++)
                if (j != ind)
                    rem.push_back(j);
            seq[rem[0]].first--;
            seq[rem[1]].first--;
            cnt[rem[0]][rem[1]]++;
        }
        while (cnt[0][2]--) {
            res += seq[0].second;
            res += seq[2].second;
        }
        while (cnt[1][2]--) {
            res += seq[1].second;
            res += seq[2].second;
        }
        while (cnt[0][1]--) {
            res += seq[1].second;
            res += seq[0].second;
        }
        cout << res << "\n";
    }
    return 0;
}
