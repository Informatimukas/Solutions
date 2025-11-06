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
        int x;
        cin >> x;
        if (*ranges::min_element(a) <= x && x <= *ranges::max_element(a))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
