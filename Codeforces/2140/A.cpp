#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        ranges::sort(t);
        int res = 0;
        for (int i = 0; i < n; i++)
            res += s[i] != t[i];
        cout << res / 2 << "\n";
    }
    return 0;
}