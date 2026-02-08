#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        ranges::sort(a);
        bool ok = true;
        for (int i = 1; i < a.size(); i++)
            if (a[i].second % 2 == a[i - 1].second % 2) {
                ok = false;
                break;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
