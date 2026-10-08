#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int xr = 0;
        multiset S = {0};
        for (auto& x : a) {
            cin >> x;
            xr ^= x;
            S.insert(x);
        }
        vector<int> b(n);
        for (auto& x : b) {
            cin >> x;
            xr ^= x;
        }
        bool bad = false;
        if (!S.contains(xr))
            bad = true;
        else S.erase(S.find(xr));
        for (auto x : b)
            if (!S.contains(x ^ xr))
                bad = true;
            else S.erase(S.find(x ^ xr));
        cout << (bad ? "NO" : "YES") << "\n";
    }
    return 0;
}
