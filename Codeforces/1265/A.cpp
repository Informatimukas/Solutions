#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '?')
                for (s[i] = 'a'; s[i] <= 'c'; s[i]++)
                    if ((i == 0 || s[i - 1] != s[i]) && (i + 1 >= s.length() || s[i] != s[i + 1]))
                        break;
        if (ranges::adjacent_find(s) != s.end())
            cout << "-1\n";
        else cout << s << "\n";
    }
    return 0;
}
