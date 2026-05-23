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
        int res = (*ranges::max_element(a) - *ranges::min_element(a) + 1) / 2;
        cout << res << "\n";
    }
    return 0;
}
