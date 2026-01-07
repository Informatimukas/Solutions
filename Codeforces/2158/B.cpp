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
        vector cnt(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            int a;
            cin >> a;
            ++cnt[a];
        }
        int odd = 0, goodEven = 0, badEven = 0;
        for (auto x : cnt)
            if (x > 0) {
                if (x % 2) ++odd;
                else if (x % 4) ++goodEven;
                else ++badEven;
            }
        int res = odd + goodEven * 2 + badEven / 2 * 4;
        if (badEven % 2 && odd >= 2)
            res += 2;
        cout << res << "\n";
    }
    return 0;
}
