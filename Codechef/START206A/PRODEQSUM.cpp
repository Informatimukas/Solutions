#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr ll Inf = 400000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ii> seq;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1)
                res++;
            else seq.emplace_back(i, a);
        }
        for (int i = 0; i < seq.size(); i++) {
            ll mult = 1, sum = 0;
            ll lef = i ? seq[i].first - seq[i - 1].first - 1 : seq[i].first;
            for (int j = i; j < seq.size(); j++) {
                mult *= seq[j].second;
                if (mult > Inf)
                    break;
                if (j > i)
                    sum += seq[j].first - seq[j - 1].first - 1;
                sum += seq[j].second;
                ll rig = j + 1 < seq.size() ?
                    seq[j + 1].first - seq[j].first - 1 : n - 1 - seq[j].first;
                ll z = mult - sum;
                ll L = max(0ll, z - rig);
                ll R = min(lef, z);
                if (L <= R)
                    res += R - L + 1ll;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
