#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;
using llb = pair<ll, bool>;

ll getValue(ll lef, ll rig, const vector<llll>& ac, int p) {
    ll res = -p;
    auto ind = distance(ac.begin(),
        ranges::lower_bound(ac, llll{rig, 0ll}));
    if (ind)
        res += ac[ind - 1].second;
    ind = distance(ac.begin(), ranges::lower_bound(ac, llll{lef, 0ll}));
    if (ind)
        res -= ac[ind - 1].second;
    return max(0ll, res);
}

void Add(deque<pair<ll, llb>>& M, ll key, ll value) {
    if (!M.empty() && (key <= M.back().first || M.back().second.first >= value))
        return;
    M.push_back({key, {value, false}});
}

void insertNext(deque<pair<ll, llb>>& M, int x, int y, const vector<llll>& ac, int p) {
    if (M.begin()->second.second)
        return;
    M.begin()->second.second = true;
    ll nxt = M.begin()->second.first +
                    getValue(M.begin()->first, M.begin()->first + x, ac, p);
    ll key = M.begin()->first + y;
    Add(M, key, nxt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, p, x, y;
        cin >> n >> p >> x >> y;
        vector<llll> ac(n);
        for (int i = 0; i < n; i++)
            cin >> ac[i].first;
        for (int i = 0; i < n; i++)
            cin >> ac[i].second;
        ranges::sort(ac);
        for (int i = 1; i < n; i++)
            ac[i].second += ac[i - 1].second;
        deque<pair<ll, llb>> M;
        Add(M, -10000000000ll, 0);
        for (int i = 0; i < n; i++) {
            while (true) {
                insertNext(M, x, y, ac, p);
                auto fol = next(M.begin());
                if (fol != M.end() && fol->first <= ac[i].first + 1 - x)
                    M.pop_front();
                else break;
            }
            ll best = M.begin()->second.first +
                getValue(ac[i].first + 1 - x, ac[i].first + 1, ac, p);
            Add(M, ac[i].first + 1 - x + y, best);
        }
        ll res = 0;
        while (!M.empty()) {
            res = max(res, M.begin()->second.first);
            insertNext(M, x, y, ac, p);
            M.pop_front();
        }
        cout << res << "\n";
    }
    return 0;
}
