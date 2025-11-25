#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<int, 2> cnt{};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < cnt.size(); j++) {
            int a;
            cin >> a;
            cnt[j] += a;
        }
    int res = min(cnt[0], n - cnt[0]) + min(cnt[1], n - cnt[1]);
    cout << res << "\n";
    return 0;
}
