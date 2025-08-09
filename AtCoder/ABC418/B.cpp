#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ld res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 't') {
            int cnt = 1;
            for (int j = i + 1; j < s.length(); j++) {
                cnt += s[j] == 't';
                if (s[j] == 't' && j - i + 1 >= 3)
                    res = max(res, static_cast<ld>(cnt - 2) / (j - i - 1));
            }
        }
    cout << fixed << setprecision(15) << res << "\n";
    return 0;
}
