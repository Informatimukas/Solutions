#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        set<int> S;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            S.insert(a);
        }
        optional<int> res;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (S.contains(a))
                res = a;
        }
        if (res) {
            cout << "YES\n";
            cout << "1 " << *res << "\n";
        } else cout << "NO\n";
    }
    return 0;
}
