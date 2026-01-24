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
        if (s.substr(s.length() - 2) == "po")
            cout << "FILIPINO\n";
        else if (s.length() >= 5 && s.substr(s.length() - 5) == "mnida")
            cout << "KOREAN\n";
        else cout << "JAPANESE\n";
    }
    return 0;
}
