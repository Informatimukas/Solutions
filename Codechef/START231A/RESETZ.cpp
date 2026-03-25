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
        int mx = *ranges::max_element(a);
        map<int, int> M;
        for (auto x : a)
            if (x < mx)
                M[x]++;
        bool ok = true;
        for (auto &value: M | views::values)
            if (value > 1) {
                ok = false;
                break;
            }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
