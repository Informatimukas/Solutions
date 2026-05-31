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
        array<int, 3> cnt{};
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int res = cnt[0];
        int tk = min(cnt[1], cnt[2]);
        res += tk;
        cnt[1] -= tk;
        cnt[2] -= tk;
        res += cnt[1] / 3 + cnt[2] / 3;
        cout << res << "\n";
    }
    return 0;
}
