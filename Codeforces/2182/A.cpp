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
        string s;
        cin >> s;
        if (s.find("2026") != string::npos)
            cout << "0\n";
        else if (s.find("2025") == string::npos)
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
