#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
        }
        vector<ii> seq;
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            seq.emplace_back(b, i);
        }
        ranges::sort(seq, greater());
        vector<int> res;
        for (auto [b, ind] : seq)
            while (b <= k) {
                res.push_back(ind);
                b++;
            }
        cout << res.size() << "\n";
        if (res.empty())
            cout << "\n";
        else for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
