#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Switch(set<int>& S, int x) {
    if (S.contains(x))
        S.erase(x);
    else S.insert(x);
}

optional<ii> Get(const set<ii>& taken, const vector<int>& a, const vector<int>& b) {
    for (auto& x : a)
        for (auto& y : b) {
            if (x == y)
                continue;
            ii p = {min(x, y), max(x, y)};
            if (!taken.contains(p))
                return p;
        }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> res(n + 1);
    res[n] = 0;
    for (int i = n - 2; i >= 0; i -= 2) {
        vector<int> cnt(k + 1);
        for (int j = i; j < n; j++)
            cnt[a[j]]++;
        set<ii> taken;
        set<int> S;
        for (int j = i; j < n; j += 2) {
            Switch(S, a[j]);
            Switch(S, a[j + 1]);
            if (S.size() == 2) {
                ii p = {*S.begin(), *S.rbegin()};
                if (taken.insert(p).second)
                    res[i] = max(res[i], (j - i) / 2 + res[j + 2]);
            }
        }
        array<vector<int>, 2> bycnt{};
        for (int j = 1; j <= k; j++)
            bycnt[cnt[j] % 2].push_back(j);
        optional<ii> p;
        for (int j = 0; j < 2; j++)
            for (int l = j; l < 2; l++)
                if (!p)
                    p = Get(taken, bycnt[j], bycnt[l]);
        if (p) {
            int u = p->first;
            int v = p->second;
            int cand = 0;
            for (int j = 1; j <= k; j++) {
                int my = cnt[j];
                if (j != u && j != v)
                    ++my;
                cand += my / 2;
            }
            res[i] = max(res[i], cand);
        }
    }
    set<int> S;
    int ans = 0;
    for (int i = 0; i < k; i++)
        Switch(S, a[i]);
    for (int i = k; i < n; i += 2) {
        if (S.size() == k) {
            cout << ans + res[i] << "\n";
            return 0;
        }
        ++ans;
        Switch(S, a[i]);
        Switch(S, a[i + 1]);
    }
    cout << n / 2 - S.size() / 2 << "\n";
    return 0;
}
