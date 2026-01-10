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
        int ones = 0;
        bool oth = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1)
                ++ones;
            else oth = true;
        }
        bool win = !oth && ones % 2 || oth && ones % 2 == 0;
        cout << (win ? "Alice" : "Bob") << "\n";
    }
    return 0;
}