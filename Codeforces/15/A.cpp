#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    t *= 2;
    vector<ii> seq(n);
    for (auto& [a, b] : seq) {
        cin >> a >> b;
        a *= 2;
    }
    ranges::sort(seq);
    int res = 2;
    for (int i = 0; i + 1 < seq.size(); i++) {
        int dist = seq[i + 1].first - seq[i + 1].second - (seq[i].first + seq[i].second);
        if (dist == t) res++;
        else if (dist > t) res += 2;
    }
    cout << res << '\n';
    return 0;
}
