#include <bits/stdc++.h>
using namespace std;

int getLeft(const string& s, int x) {
    for (int i = x - 1; i >= 0; i--)
        if (s[i] == '#')
            return i + 2;
    return 1;
}

int getRight(const string& s, int x) {
    for (int i = x + 1; i < s.length(); i++)
        if (s[i] == '#')
            return s.length() - 1 - i + 2;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        x--;
        if (x == 0 || x == n - 1) {
            cout << "1\n";
            continue;
        }
        int res = max(min(getLeft(s, x), n - x),
                        min(getRight(s, x), x + 1));
        cout << res << "\n";
    }
    return 0;
}