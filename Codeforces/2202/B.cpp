#include <bits/stdc++.h>
using namespace std;

bool Solve(const string& s) {
    int st = s.length() % 2? 0 : 3;
    for (auto ch : s)
        if (st == 0) {
            if (ch == 'b')
                return false;
            st = 3;
        } else if (st == 1) {
            if (ch == 'a')
                return false;
            st = 3;
        } else if (st == 2)
            st = 3;
        else if (ch == 'a')
            st = 1;
        else if (ch == 'b')
            st = 0;
        else st = 2;
    return true;
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
        cout << (Solve(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}
