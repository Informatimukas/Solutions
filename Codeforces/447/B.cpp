#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    array<int, Maxl> w{};
    int mx = 0;
    for (auto& x : w) {
        cin >> x;
        mx = max(mx, x);
    }
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res += w[s[i] - 'a'] * (i + 1);
    for (int i = s.length() + 1; i <= s.length() + k; i++)
        res += i * mx;
    cout << res << "\n";
    return 0;
}
