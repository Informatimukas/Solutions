#include <bits/stdc++.h>
using namespace std;

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
        for (auto& x : a)
            cin >> x;
        vector<int> tmp(n);
        iota(tmp.begin(), tmp.end(), 1);
        set S(tmp.begin(), tmp.end());
        set<int> special;
        for (int i = 0; i < n; i++) {
            int sum = a[i];
            auto it = S.begin();
            for (int j = i + 1; j < n && it != S.end(); j++) {
                sum += a[j];
                while (it != S.end() && *it < sum)
                    ++it;
                if (it != S.end() && *it == sum) {
                    special.insert(*it);
                    S.erase(it++);
                }
            }
        }
        cout << ranges::count_if(a, [&](auto&& x) { return special.contains(x); }) << "\n";
    }
    return 0;
}
