#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    int res = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i <= s.length() && i <= k; i++)
            if (s[s.length() - i] != '0') {
                s.erase(s.begin() + s.length() - i);
                res++;
                flag = true;
                break;
            }
    }
    if (s[0] == '0')
        res += s.length() - 1;
    cout << res << "\n";
    return 0;
}
