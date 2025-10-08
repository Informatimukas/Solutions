#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<int> getSpecial(const vector<ii>& seq) {
    vector<int> res(seq.size());
    for (int i = 1, j; i < seq.size(); i = j) {
        j = i;
        while (j < seq.size() && seq[i].first == seq[j].first)
            j++;
        if (j - i == 1)
            return {};
        res[seq[i].second] = seq[j - 1].second;
        for (int z = i + 1; z < j; z++)
            res[seq[z].second] = seq[z - 1].second;
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
        int n;
        cin >> n;
        vector<ii> seq(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> seq[i].first;
            seq[i].second = i;
        }
        sort(seq.begin() + 1, seq.end());
        auto got = getSpecial(seq);
        if (!got.empty()) {
            cout << n << "\n";
            for (int i = 1; i < got.size(); i++)
                cout << got[i] << (i + 1 < got.size() ? ' ' : '\n');
            continue;
        }
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
            if (i == 1) res[seq[i].second] = seq[n].second;
            else res[seq[i].second] = seq[i - 1].second;
        int ans = n - 1 + (seq[1].first == seq.back().first);
        cout << ans << "\n";
        for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
