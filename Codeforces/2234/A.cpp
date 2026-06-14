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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a, greater());
        bool bad = false;
        for (int i = 0; i + 3 <= n; i++)
            if (a[i] % a[i + 1] != a[i + 2]) {
                bad = true;
                break;
            }
        if (bad) {
            cout << "-1\n";
            continue;
        }
        cout << a[0] << " " << a[1] << "\n";
    }
    return 0;
}
