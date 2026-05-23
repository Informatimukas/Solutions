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
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                swap(a[i], b[i]);
        auto res = accumulate(b.begin(), b.end(), 0ll) + *ranges::max_element(a);
        cout << res << "\n";
    }
    return 0;
}
