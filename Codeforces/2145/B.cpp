#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int lef = 0, rig = 0, both = 0;
        for (auto& ch : s)
            if (ch == '0')
                lef++;
            else if (ch == '1')
                rig++;
            else both++;
        if (k == n) {
            cout << string(n, '-') << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
            if (i < lef || n - 1 - i < rig)
                cout << "-";
            else if (i < lef + both || n - 1 - i < rig + both)
                cout << "?";
            else cout << "+";
        cout << "\n";
    }
    return 0;
}