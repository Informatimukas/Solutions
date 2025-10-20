#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ii> seq(n);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    ld res = 0;
    for (int i = 1; i < seq.size(); i++)
        res += sqrt((seq[i].first - seq[i - 1].first) * (seq[i].first - seq[i - 1].first) +
            (seq[i].second - seq[i - 1].second) * (seq[i].second - seq[i - 1].second));
    cout << fixed << setprecision(10) << res * k / 50 << "\n";
    return 0;
}