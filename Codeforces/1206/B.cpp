#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<ll, 2> dp = {0, Inf};
    array targ = {1, -1};
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        array ndp = {Inf, Inf};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                ll cand = dp[i] + abs(a - targ[j]);
                int nj = (i + j) % 2;
                ndp[nj] = min(ndp[nj], cand);
            }
        dp = std::move(ndp);
    }
    cout << dp[0] << "\n";
    return 0;
}
