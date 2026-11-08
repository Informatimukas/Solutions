#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    int ind{};
    ll sum{};
    ll cnt{};
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pos> S;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos p{i, 0, 1};
            res += i;
            while (!S.empty() && a[S.back().ind] < a[p.ind]) {
                auto prv = S.back();
                S.pop_back();
                if (!S.empty() && a[S.back().ind] < a[p.ind])
                    prv.sum = prv.ind - S.back().ind - 1;
                prv.sum += prv.cnt;
                res += prv.sum;
                p.sum += prv.sum;
                p.cnt += prv.cnt;
                res += (prv.sum + prv.cnt) * (p.ind - prv.ind - 1);
            }
            S.push_back(p);
        }
        cout << res << "\n";
    }
    return 0;
}
