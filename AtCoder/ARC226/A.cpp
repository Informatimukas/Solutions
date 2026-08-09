#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int mod = 998244353;

int Solve(vector<ii> seq) {
    ranges::sort(seq);
    int a = -1, b = -1;
    int res = 1;
    for (auto [lef, rig] : seq)
        if (b <= lef) {
            res = 2 * res % mod;
            b = rig;
        } else if (a <= lef) {
            a = rig;
            if (a > b)
                swap(a, b);
        } else return 0;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> seq(n);
    for (auto& [lef, rig] : seq)
        cin >> lef >> rig;
    cout << Solve(seq) << "\n";
    return 0;
}
