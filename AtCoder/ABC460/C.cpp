#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::sort(a);
    multiset<int> S;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        S.insert(b);
    }
    int res = 0;
    for (auto x : a) {
        auto it = S.upper_bound(2 * x);
        if (it != S.begin()) {
            --it;
            res++;
            S.erase(it);
        }
    }
    cout << res << "\n";
    return 0;
}
