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
        map<int, int> M;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                M[a]++;
            }
        int mx = 0;
        for (auto& [key, val] : M)
            mx = max(mx, val);
        if (mx > n * (n - 1))
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
