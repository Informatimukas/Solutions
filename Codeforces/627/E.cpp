#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    int val;
    int left, right;
};

ll Solve(const vector<string>& B, int k) {
    if (k == 0)
        return 0;
    int n = B.size();
    int m = B[0].length();
    vector my(n, deque<int>());
    ll res = 0;
    for (int j = m - 1; j >= 0; j--) {
        ll cur = 0;
        list<pos> L;
        for (int i = n - 1; i >= 0; i--) {
            if (B[i][j] == '1') {
                if (my[i].size() >= k)
                    my[i].pop_back();
                my[i].push_front(j);
            }
            cur += my[i].size() < k ? m : my[i].back();
            for (auto& val : my[i]) {
                int lef = i + 1, rig = i;
                auto it = L.begin();
                while (it != L.end() && it->val >= val) {
                    if (it->right > rig) {
                        cur -= it->val * (it->right - rig);
                        swap(it->right, rig);
                    }
                    if (it->left > it->right) {
                        L.erase(it++);
                        continue;
                    }
                    if (lef <= it->right) {
                        cur += it->val * (it->right - lef + 1);
                        lef = it->right + 1;
                    }
                    ++it;
                }
                cur += val * (rig - lef + 1);
                L.insert(it, {val, i, rig});
            }
            auto it = L.begin();
            for (int z = 0; z < k - my[i].size(); z++)
                if (it != L.end() && it->val == m) {
                    it->left = i;
                    ++it;
                } else L.insert(it, {m, i, i});
            res += cur - static_cast<ll>(n - i) * j;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c, n, k;
    cin >> r >> c >> n >> k;
    vector B(r, string(c, '0'));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        B[x - 1][y - 1] = '1';
    }
    ll res = static_cast<ll>(r) * (r + 1) * c * (c + 1) / 4 - Solve(B, k);
    cout << res << "\n";
    return 0;
}