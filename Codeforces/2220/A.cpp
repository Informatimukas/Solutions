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
        if (ranges::adjacent_find(a) != a.end()) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
