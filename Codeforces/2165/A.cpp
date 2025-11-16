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
        vector<int> a(n);
        map<int, vector<int>> M;
        set<int> S;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            M[a[i]].push_back(i);
            S.insert(i);
        }
        ll res = 0;
        for (auto& V : M | views::values)
            for (auto& x : V)
                if (S.contains(x)) {
                    auto it = S.find(x);
                    ++it;
                    while (true) {
                        if (it == S.end())
                            it = S.begin();
                        if (*it != x && a[x] >= a[*it]) {
                            res += a[x];
                            S.erase(it++);
                        } else break;
                    }
                    it = S.find(x);
                    while (true) {
                        if (it == S.begin())
                            it = S.end();
                        --it;
                        if (*it != x && a[x] >= a[*it]) {
                            res += a[x];
                            S.erase(it++);
                        } else break;
                    }
                }
        cout << res << "\n";
    }
    return 0;
}
