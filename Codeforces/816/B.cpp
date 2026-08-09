#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, q;
    cin >> n >> k >> q;
    vector delt(Maxn, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        delt[l]++;
        delt[r + 1]--;
    }
    vector cnt(Maxn, 0);
    int cur = 0;
    for (int i = 0; i < Maxn; i++) {
        cur += delt[i];
        if (cur >= k)
            cnt[i] = 1;
        if (i)
            cnt[i] += cnt[i - 1];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << cnt[b] - cnt[a - 1] << "\n";
    }
    return 0;
}
