#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool bobWins(const string& s) {
    int st = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        st += s[i] == 'B' ? 1 : -1;
        if (st < 0)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << "Case #" << tc << ": " << (bobWins(s) ? "Bob" : "Alice") << "\n";
    }
    return 0;
}