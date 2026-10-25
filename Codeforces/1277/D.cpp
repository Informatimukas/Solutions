#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        array<array<set<int>, 2>, 2> has;
        array<array<bool, 2>, 2> was{};
        map<string, int> M;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            has[s[0] - '0'][s.back() - '0'].insert(i);
            M[s] = i;
            was[s[0] - '0'][s.back() - '0'] = true;
            if (s[0] == s.back())
                continue;
            string rev = s;
            ranges::reverse(rev);
            if (M.contains(rev)) {
                has[s[0] - '0'][s.back() - '0'].erase(i);
                has[s.back() - '0'][s[0] - '0'].erase(M[rev]);
                M.erase(rev);
                M.erase(s);
            }
        }
        if (!was[0][1] && !was[1][0] && was[0][0] && was[1][1]) {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        for (int z = 0; z < 2; z++) {
            int nz = 1 - z;
            while (has[z][nz].size() > has[nz][z].size() + 1) {
                res.push_back(*has[z][nz].begin());
                has[nz][z].insert(*has[z][nz].begin());
                has[z][nz].erase(has[z][nz].begin());
            }
        }
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
