#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        vector<int> seq;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            while (!seq.empty() && a[seq.back()] < a[i])
                seq.pop_back();
            int cnt;
            if (a[i] == b[i]) cnt = i + 1;
            else {
                auto ind = distance(seq.begin(),
                    ranges::partition_point(seq, [&](const int& x) {
                        return a[x] >= max(a[i], b[i]);
                    })) - 1;
                if (ind < 0) cnt = 0;
                else cnt = seq[ind] + 1;
            }
            seq.push_back(i);
            res += static_cast<ll>(cnt) * (n - i);
        }
        cout << res << "\n";
    }
    return 0;
}
