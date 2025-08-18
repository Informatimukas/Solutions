#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    while (true) {
        auto pos = s.find("dot", 1);
        if (pos == string::npos || pos + 3 == s.length())
            break;
        s.replace(pos, 3, ".");
    }
    auto pos = s.find("at", 1);
    if (pos != string::npos && pos + 2 != s.length())
        s.replace(pos, 2, "@");
    cout << s << "\n";
    return 0;
}
