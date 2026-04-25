#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    map<ll, int> M;
    int best{1000000000};
};

void Add(pos& p, ll key, int val) {
    if (key == 1)
        return;
    auto it = p.M.lower_bound(key);
    if (it != p.M.end() && it->first == key)
        it->second = min(it->second, val);
    else p.M.insert(it, {key, val});
    p.best = min(p.best, val);
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
        vector<pos> p(n + 1);
        for (int i = n; i >= 1; i--) {
            ll a;
            cin >> a;
            int k;
            cin >> k;
            int sum = 0;
            vector<int> neigh(k);
            for (auto& x : neigh) {
                cin >> x;
                sum += p[x].best;
            }
            for (auto& u : neigh) {
                for (auto& [key, val] : p[u].M)
                    Add(p[i], __gcd(key, a), sum - p[u].best + val);
                map<ll, int> empty;
                swap(p[u].M, empty);
            }
            Add(p[i], a, sum + 1);
            cout << p[i].best << endl;
            auto it1 = p[i].M.end();
            while (it1 != p[i].M.begin()) {
                --it1;
                auto it2 = next(it1);
                while (it2 != p[i].M.end()) {
                    auto cand = __gcd(it1->first, it2->first);
                    if (cand > 1) {
                        Add(p[i], cand, it2->second);
                        p[i].M.erase(it2++);
                    } else ++it2;
                }
            }
        }
    }
    return 0;
}
