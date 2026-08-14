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
        int res = 0;
        while (a[0] < a[1] && a[1] < a[2]) {
            res++;
            a[0]++; a[2]--;
            ranges::sort(a);
        }
        cout << res << "\n";
    }
    return 0;
}
