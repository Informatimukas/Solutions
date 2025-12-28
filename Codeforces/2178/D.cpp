#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

void Hit(vector<ii>& seq, int x, int y, vector<ii>& res) {
    res.emplace_back(seq[x].second, seq[y].second);
    seq[y].first -= seq[x].first;
}

void Print(const vector<ii>& res) {
    cout << res.size() << "\n";
    for (auto& [x, y] : res)
        cout << x + 1 << " " << y + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ii> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> seq[i].first;
            seq[i].second = i;
        }
        ranges::sort(seq);
        if (2 * m > n) {
            cout << "-1\n";
            continue;
        }
        vector<ii> res;
        if (m == 0) {
            ll sum = 0;
            for (int i = 0; i + 1 < n; i++)
                sum += seq[i].first;
            if (sum < seq[n - 1].first) {
                cout << "-1\n";
                continue;
            }
            int pnt = 0;
            while (seq[pnt].first < seq[n - 1].first) {
                Hit(seq, pnt, n - 1, res);
                ++pnt;
            }
            while (pnt + 1 < n) {
                Hit(seq, pnt, pnt + 1, res);
                ++pnt;
            }
            Print(res);
            continue;
        }
        int need = n - 2 * m;
        for (int i = 0; i < need; i++)
            Hit(seq, i, i + 1, res);
        for (int i = n - 1; i >= n - m; i--)
            Hit(seq, i, i - m, res);
        Print(res);
    }
    return 0;
}
