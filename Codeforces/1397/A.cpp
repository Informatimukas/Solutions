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
        map<char, int> M;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (auto& ch : s)
                M[ch]++;
        }
        bool ok = true;
        for (auto& val : M | views::values)
            if (val % n)
                ok = false;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
