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
        vector<int> a(2 * n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        cout << a[n] - a[n - 1] << "\n";
    }
    return 0;
}
