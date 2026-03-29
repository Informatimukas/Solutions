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
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            a[p] = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i] = a[b[i]];
        }
        cout << (ranges::is_sorted(b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
