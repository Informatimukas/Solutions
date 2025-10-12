#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 1) {
            int res = 0;
            while (k--) {
                int x, y;
                cin >> x >> y;
                if (y == 2)
                    res ^= 1;
            }
            cout << (res ? "Mimo" : "Yuyu") << "\n";
            continue;
        }
        set<int> S;
        while (k--) {
            int x, y;
            cin >> x >> y;
            if (y > 1) {
                if (S.contains(y))
                    S.erase(y);
                else S.insert(y);
            }
        }
        cout << (S.empty() ? "Yuyu" : "Mimo") << "\n";
    }
    return 0;
}