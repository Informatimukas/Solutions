#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> my(n + 1);
        ll sum = 0;
        multiset<int> S;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            my[y].push_back(x);
        }
        vector<ll> dif(n + 1);
        ll maxbest = -Inf;
        for (int i = n; i >= 0; i--) {
            for (auto x : my[i]) {
                S.insert(x);
                sum += x;
            }
            while (S.size() > i + 1) {
                sum -= *S.begin();
                S.erase(S.begin());
            }
            maxbest = max(maxbest, sum);
            dif[i] = S.size() == i + 1 ? sum - *S.begin() : sum;
        }
        vector<vector<ii>> quer(n + 1);
        vector<ll> ans(m);
        ll maxdif = -Inf;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            quer[y].emplace_back(x, i);
        }
        for (int i = 0; i <= n; i++) {
            maxdif = max(maxdif, dif[i]);
            for (auto [x, ind] : quer[i])
                ans[ind] = max(maxbest, maxdif + x);
        }
        for (int i = 0; i < m; i++)
            cout << ans[i] << (i + 1 < m ? ' ' : '\n');
    }
    return 0;
}
