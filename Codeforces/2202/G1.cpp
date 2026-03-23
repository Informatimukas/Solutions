#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ii = pair<int, int>;

constexpr int Maxb = 64;

int Bad(const vector<ull>& A, const vector<ull>& B) {
    for (int i = 0; i < A.size(); i++)
        if ((A[i] & B[i]) != A[i])
            return 1;
    return 0;
}

void Erase(set<ii>& S, const ii& p, int& bad, const vector<vector<ull>>& my) {
    auto it = S.find(p);
    auto nxt = next(it);
    auto prv = it == S.begin() ? it : prev(it);
    if (nxt != S.end()) {
        bad -= Bad(my[p.second], my[nxt->second]);
        if (it != S.begin())
            bad += Bad(my[prv->second], my[nxt->second]);
    }
    if (it != S.begin())
        bad -= Bad(my[prv->second], my[p.second]);
    S.erase(it);
}

void Insert(set<ii>& S, const ii& p, int& bad, const vector<vector<ull>>& my) {
    auto nxt = S.lower_bound(p);
    auto prv = nxt == S.begin() ? nxt : prev(nxt);
    if (nxt != S.end()) {
        bad += Bad(my[p.second], my[nxt->second]);
        if (nxt != S.begin())
            bad -= Bad(my[prv->second], my[nxt->second]);
    }
    if (nxt != S.begin())
        bad += Bad(my[prv->second], my[p.second]);
    S.insert(nxt, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        int nd = (n - 1) / Maxb + 1;
        vector my(n, vector(nd, 0ull));
        vector cnt(n, 0);
        set<ii> S;
        for (int j = 0; j < n; j++)
            S.emplace(0, j);
        int bad = 0;
        while (q--) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            Erase(S, {cnt[r], r}, bad, my);
            ++cnt[r];
            my[r][c / Maxb] |= 1ull << c % Maxb;
            Insert(S, {cnt[r], r}, bad, my);
            cout << (bad ? "NO" : "YES") << "\n";
        }
    }
    return 0;
}
