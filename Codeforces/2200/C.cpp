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
        string s;
        cin >> s;
        vector<char> S;
        for (int i = 0; i < s.length(); i++)
            if (!S.empty() && S.back() == s[i])
                S.pop_back();
            else S.push_back(s[i]);
        cout << (S.empty() ? "YES" : "NO") << "\n";
    }
    return 0;
}
