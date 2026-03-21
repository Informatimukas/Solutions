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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int t = 0; t < 20; t++)
            for (int i = n; i >= 1; i--)
                if (i % 2 == 0 && a[i / 2] > a[i])
                    swap(a[i / 2], a[i]);
        cout << (is_sorted(a.begin() + 1, a.end()) ? "YES" : "NO") << "\n";
    }
    return 0;
}
