#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        array<int, Maxl> freq{};
        for (auto& ch : s)
            freq[ch - 'a']++;
        auto ind = distance(freq.begin(), ranges::max_element(freq));
        if (freq[ind] > s.length() - freq[ind]) {
            string oth;
            for (auto& ch : s)
                if (ch != ind + 'a')
                    oth += ch;
            for (int i = 0; i <= oth.length(); i++) {
                int tk = freq[ind] / (oth.length() + 1 - i);
                if (i < oth.length() && tk % 2 == 0)
                    tk++;
                cout << string(tk, 'a' + ind);
                freq[ind] -= tk;
                if (i < oth.length())
                    cout << oth[i];
            }
            cout << "\n";
            continue;
        }
        string res;
        while (res.size() < s.length()) {
            array<ii, 2> best{};
            for (int i = 0; i < Maxl; i++) {
                ii cand = {freq[i], i};
                if (cand > best[0]) {
                    best[1] = best[0];
                    best[0] = cand;
                } else if (cand > best[1])
                    best[1] = cand;
            }
            res += best[0].second + 'a';
            freq[best[0].second]--;
            if (best[1].first) {
                res += best[1].second + 'a';
                freq[best[1].second]--;
            }
        }
        int pnt = res.length() - 1;
        if (pnt % 2 == 0)
            pnt--;
        while (pnt > 0) {
            if (pnt + 1 < res.length() && res[pnt] == res[pnt + 1])
                swap(res[pnt - 1], res[pnt]);
            pnt -= 2;
        }
        cout << res << "\n";
    }
    return 0;
}
