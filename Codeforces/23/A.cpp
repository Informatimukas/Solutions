#include <bits/stdc++.h>
using namespace std;

bool Check(const string& s, int len) {
    set<string> S;
    for (int i = 0; i + len <= s.length(); i++)
        if (!S.insert(s.substr(i, len)).second)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int x = 1;
    while (Check(s, x))
        x++;
    cout << x - 1 << "\n";
    return 0;
}
