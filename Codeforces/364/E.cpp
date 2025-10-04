#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    int row;
    int cnt;
    vector<int> my;
    pos(int row, deque<int>& D): row(row), cnt(1), my(D.begin(), D.end()) {}
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
            L.push_front(pos(i, my[i]));
            cur += L.front().my.back();
            for (auto& el : L.front().my) {
                auto itp = L.begin();
                auto it = next(L.begin());
                while (it != L.end() && el < it->my.back()) {
                    cur -= static_cast<ll>(it->my.back()) * it->cnt;
                    it->my.pop_back();
                    if (it->my.empty()) {
                        itp->cnt += it->cnt;
                        cur += static_cast<ll>(itp->my.back()) * it->cnt;
                        L.erase(it++);
                    } else {
                        cur += static_cast<ll>(it->my.back()) * it->cnt;
                        itp = it++;
                    }
                }
            }
            res += cur - static_cast<ll>(n - i) * i;
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