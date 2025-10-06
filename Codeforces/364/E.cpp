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
    vector my(n, deque(k, m));
    ll res = 0;
    for (int j = m - 1; j >= 0; j--) {
        ll cur = 0;
        list<pos> L;
        for (int i = n - 1; i >= 0; i--) {
            if (B[i][j] == '1') {
                my[i].pop_back();
                my[i].push_front(j);
            }
            cur += my[i].back();
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
            res += cur - static_cast<ll>(n - i) * j;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> B(n);
    for (auto& s : B)
        cin >> s;
    cout << Solve(B, k + 1) - Solve(B, k) << "\n";
    return 0;
}