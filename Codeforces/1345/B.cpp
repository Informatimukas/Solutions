#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector f = {2ll};
    while (f.back() <= 1000000000) {
        int ind = f.size();
        int lst = f.back();
        f.push_back(lst + 3 * ind + 2);
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        for (auto x : f | views::reverse) {
            res += n / x;
            n %= x;
        }
        cout << res << "\n";
    }
    return 0;
}
