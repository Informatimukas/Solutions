#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto& x : a)
            cin >> x;
        auto it = ranges::adjacent_find(a, [](int a, int b) {
            return a >= b;
        });
        if (it != a.end())
            cout << "1\n";
        else cout << n - a.back() + 1 << "\n";
    }
    return 0;
}