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
        string s;
        cin >> n;
        cin >> s;
        array<int, 2> cnt{};
        for (auto& ch : s)
            cnt[ch - '0']++;
        int res = 1000000000;
        for (int i = 0, j; i < s.length(); i = j) {
            j = i;
            while (j < s.length() && s[i] == s[j])
                j++;
            int my = s[i] - '0';
            res = min(res, cnt[1 - my] + 2 * (cnt[my] - (j - i)));
        }
        cout << res << "\n";
    }
    return 0;
}
