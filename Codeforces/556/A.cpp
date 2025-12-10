#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    array<int, 2> cnt{};
    for (auto& ch : s)
        cnt[ch - '0']++;
    cout << cnt[0] + cnt[1] - 2 * min(cnt[0], cnt[1]) << "\n";
    return 0;
}
