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
        array<int, 4> cnt{};
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a % 4]++;
        }
        cout << max({cnt[0], cnt[2], cnt[1] + cnt[3]}) << "\n";
    }
    return 0;
}
