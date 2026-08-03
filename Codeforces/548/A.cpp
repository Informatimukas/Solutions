#include <bits/stdc++.h>
using namespace std;

bool Palindrome(string_view s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int k;
    cin >> s >> k;
    if (s.length() % k) {
        cout << "NO\n";
        return 0;
    }
    int d = s.length() / k;
    for (int i = 0; i < s.length(); i += d)
        if (!Palindrome(s.substr(i, d))) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
