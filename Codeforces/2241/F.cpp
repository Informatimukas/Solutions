#include <bits/stdc++.h>
using namespace std;

bool Check(const string& s) {
    int cnt = 0;
    for (auto ch : s)
        if (ch == '0') {
            if (cnt % 2)
                return true;
        } else cnt++;
    cnt = 0;
    for (auto ch : s | views::reverse)
        if (ch == '1') {
            if (cnt % 2)
                return true;
        } else cnt++;
    return false;
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
        cout << (Check(s) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
