#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(k);
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            cnt[i % k] += s[i] - '0';
        cout << (ranges::all_of(cnt, [](int x) { return x % 2 == 0; }) ? "YES" : "NO") << "\n";
    }
    return 0;
}
