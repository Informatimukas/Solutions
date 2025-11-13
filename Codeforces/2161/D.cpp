#include <bits/stdc++.h>
using namespace std;

void Add(map<int, int>& M, int key, int val) {
    auto it = M.lower_bound(key);
    if (it != M.end() && it->second >= val)
        return;
    while (it != M.begin()) {
        --it;
        if (val >= it->second)
            M.erase(it++);
        else break;
    }
    M.emplace(key, val);
}

int Get(map<int, int>& M, int key) {
    return M.lower_bound(key)->second;
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
        vector seq(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            seq[a].push_back(i);
        }
        map<int, int> cur = {{n, 0}};
        for (int i = 1; i <= n; i++) {
            map<int, int> M;
            Add(M, n, Get(cur, 0));
            int cand = 0;
            for (auto& x : seq[i] | views::reverse) {
                cand = max(cand, Get(cur, x)) + 1;
                Add(M, x, cand);
            }
            cur = std::move(M);
        }
        cout << n - Get(cur, 0) << "\n";
    }
    return 0;
}
