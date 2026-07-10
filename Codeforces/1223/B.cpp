#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    while (Q--) {
        string s;
        string t;
        cin >> s >> t;
        set<char> S;
        for (auto ch : s)
            S.insert(ch);
        bool was = false;
        for (auto ch : t)
            if (S.contains(ch)) {
                was = true;
                break;
            }
        cout << (was ? "YES" : "NO") << "\n";
    }
    return 0;
}
