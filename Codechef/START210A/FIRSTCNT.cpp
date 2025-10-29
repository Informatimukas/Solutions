#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ii> seq(n);
        vector res(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> seq[i].first;
            seq[i].second = i;
        }
        ranges::sort(seq);
        res[seq[0].second] += Inf;
        for (int i = 0; i < n - 1; i++) {
            int dif = seq[i + 1].first - seq[i].first;
            res[seq[i + 1].second] += (dif + 1) / 2;
            res[seq[i].second] += dif - (dif + 1) / 2;
        }
        res[seq.back().second] += Inf;
        for (int i = 0; i < n; i++)
            cout << (res[i] >= Inf ? -1 : res[i]) << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
