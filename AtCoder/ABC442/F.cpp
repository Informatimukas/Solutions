#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int cur = 0;
        for (auto ch : s)
            cur += ch != '#';
        res[0] += cur;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '#')
                cur++;
            else cur--;
            res[j + 1] += cur;
        }
        for (int j = n - 1; j >= 0; j--)
            res[j] = min(res[j], res[j + 1]);
    }
    cout << res[0] << "\n";
    return 0;
}
