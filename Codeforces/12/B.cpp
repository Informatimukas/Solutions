#include <bits/stdc++.h>
using namespace std;

string Solve(string s) {
    ranges::sort(s);
    for (int i = 1; i < s.size(); i++)
        if (s[i] != '0' && s[0] == '0') {
            swap(s[i], s[0]);
            return s;
        }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << (Solve(a) == b ? "OK" : "WRONG_ANSWER") << "\n";
    return 0;
}
