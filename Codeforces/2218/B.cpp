#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        array<int, 7> a{};
        for (auto& x : a)
            cin >> x;
        int res = -1000000000;
        for (int i = 0; i < a.size(); i++) {
            int cand = 0;
            for (int j = 0; j < a.size(); j++)
                cand += j == i ? a[j] : -a[j];
            res = max(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
