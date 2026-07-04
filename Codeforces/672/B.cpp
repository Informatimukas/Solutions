#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n > 26) {
        cout << "-1\n";
        return 0;
    }
    set<char> S;
    string s;
    cin >> s;
    for (auto& ch : s)
        S.insert(ch);
    cout << s.length() - S.size() << "\n";
    return 0;
}
