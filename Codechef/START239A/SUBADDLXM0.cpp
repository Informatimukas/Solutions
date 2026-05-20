#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

multiset<int>::iterator findBest(multiset<int>& S, int a, int k) {
    auto cand = S.lower_bound((k - a) % k);
    if (cand == S.end())
        cand = S.begin();
    return cand;
}

void safeDelete(multiset<int>& S, int val) {
    auto it = S.find(val);
    if (it != S.end())
        S.erase(it);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> best = a;
        for (int m = 1; m <= n; m++) {
            multiset<int> allowed;
            multiset<int> needed;
            for (int i = 0; i < m; i++) {
                allowed.insert(i % k);
                needed.insert(i % k);
            }
            vector<int> b(n);
            int cur = -1;
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    auto it = findBest(allowed, a[i], k);
                    cur = *it;
                    allowed.erase(it);
                    safeDelete(needed, cur);
                } else if (n - i == needed.size()) {
                    auto it = findBest(needed, a[i], k);
                    cur = *it;
                    needed.erase(it);
                    safeDelete(allowed, cur);
                } else if (!allowed.empty()) {
                    auto it = findBest(allowed, a[i], k);
                    if ((*it + a[i]) % k < (cur + a[i]) % k) {
                        cur = *it;
                        allowed.erase(it);
                        safeDelete(needed, cur);
                    } else if (cur == *it)
                        safeDelete(needed, cur);
                }
                b[i] = (cur + a[i]) % k;
            }
            if (b < best)
                best = b;
        }
        for (int i = 0; i < best.size(); i++)
            cout << best[i] << (i + 1 < best.size() ? ' ' : '\n');
    }
    return 0;
}
