#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    set<string> S;
    for (int i = 0; i < s.length(); i++) {
        S.insert(s);
        s = s.substr(1) + s[0];
    }
    cout << S.size() << "\n";
    return 0;
}
