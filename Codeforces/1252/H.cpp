#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<llll> seq(n);
    ll res = 0;
    for (auto& [a, b] : seq) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        res = max(res, a * b);
    }
    ranges::sort(seq, greater());
    array<ll, 2> best{};
    for (auto& [a, b] : seq) {
        if (b > best[0])
            best[1] = best[0], best[0] = b;
        else if (b > best[1])
            best[1] = b;
        res = max(res, 2 * a * best[1]);
    }
    cout << res / 2 << "." << (res % 2 ? 5 : 0) << "\n";
    return 0;
}
