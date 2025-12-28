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
        int res = 0;
        for (auto& ch : s)
            res += ch == 'Y';
        cout << (res <= 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}
