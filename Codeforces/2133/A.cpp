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
        set<int> S;
        bool was = false;
        while (n--) {
            int x;
            cin >> x;
            if (!S.insert(x).second)
                was = true;
        }
        cout << (was ? "YES" : "NO") << "\n";
    }
    return 0;
}