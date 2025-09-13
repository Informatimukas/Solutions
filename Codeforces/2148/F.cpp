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
        vector<vector<int>> B(n);
        set<int> S;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            B[i].resize(k);
            for (int j = 0; j < k; j++)
                cin >> B[i][j];
            S.insert(i);
        }
        vector<int> res;
        set<int> imp;
        for (int i = 0; ; i++) {
            if (imp.empty()) {
                for (auto it = S.begin(); it != S.end(); )
                    if (B[*it].size() <= i)
                        S.erase(it++);
                    else {
                        imp.insert(*it);
                        ++it;
                    }
                if (imp.empty()) break;
            }
            int val = numeric_limits<int>::max();
            set<int> best;
            for (auto it = imp.begin(); it != imp.end(); )
                if (B[*it].size() <= i)
                    imp.erase(it++);
                else {
                    if (B[*it][i] < val) {
                        val = B[*it][i];
                        best.clear();
                    }
                    if (B[*it][i] == val)
                        best.insert(*it);
                    ++it;
                }
            if (best.empty()) {
                i--;
                continue;
            }
            res.push_back(val);
            imp = std::move(best);
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}