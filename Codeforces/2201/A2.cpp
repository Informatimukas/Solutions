#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ill = pair<int, ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int rig = -1;
        vector<ill> seq;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ll ways = 1;
            if (x > rig + 1) {
                while (!seq.empty()) {
                    ways += seq.back().second;
                    seq.pop_back();
                }
            }
            while (!seq.empty() && seq.back().first >= x) {
                ways += seq.back().second;
                seq.pop_back();
            }
            res += ways * (n - i);
            seq.emplace_back(x, ways);
            rig = x;
        }
        cout << res << "\n";
    }
    return 0;
}
