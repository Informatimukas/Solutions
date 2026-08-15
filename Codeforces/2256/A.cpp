#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        array<int, 3> a{};
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        a[2] = min(a[2], a[0] + a[1]);
        cout << a[2] - a[0] << "\n";
    }
    return 0;
}
