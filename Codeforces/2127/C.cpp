#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        ll res = 0;
        vector<ii> seq;
        for (int i = 0; i < b.size(); i++) {
            cin >> b[i];
            if (a[i] > b[i])
                swap(a[i], b[i]);
            res += b[i] - a[i];
            seq.emplace_back(a[i], b[i]);
        }
        ranges::sort(seq);
        int lst = -Inf, best = Inf;
        for (auto& i : seq) {
            if (lst >= i.first) {
                best = 0;
                break;
            }
            best = min(best, i.first - lst);
            lst = i.second;
        }
        res += 2 * best;
        cout << res << "\n";
    }
    return 0;
}
