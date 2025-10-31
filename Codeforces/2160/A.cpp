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
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(a);
        }
        int res = 0;
        while (S.contains(res))
            res++;
        cout << res << "\n";
    }
    return 0;
}