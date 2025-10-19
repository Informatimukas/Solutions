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
        set<char> S;
        for (int i = 0; i < 2 * n + 1; i++) {
            string s;
            cin >> s;
            for (auto& ch : s)
                if (S.contains(ch))
                    S.erase(ch);
                else S.insert(ch);
        }
        cout << *S.begin() << "\n";
    }
    return 0;
}
