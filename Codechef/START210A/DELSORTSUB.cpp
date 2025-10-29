#include <bits/stdc++.h>
using namespace std;

int checkBad(const string& s, char op, char cl) {
    int st = 0;
    for (int i = 0; i < s.length(); i++) {
        st += s[i] == op ? 1 : -1;
        if (st < 0)
            return 1;
    }
    return 0;
}

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
        int res = checkBad(s, '0', '1');
        ranges::reverse(s);
        res += checkBad(s, '1', '0');
        cout << res << "\n";
    }
    return 0;
}
