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
        map<int, int> M;
        while (n--) {
            int a;
            cin >> a;
            M[a]++;
        }
        int res = 0;
        for (auto& p: M)
            res = max(res, p.second);
        cout << res << "\n";
    }
    return 0;
}