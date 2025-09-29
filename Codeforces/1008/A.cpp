#include <bits/stdc++.h>
using namespace std;

constexpr string vowels = "aouie";

bool Check(const string &s) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'n' || vowels.find(s[i]) != string::npos) ;
        else {
            if (i + 1 >= s.length() || vowels.find(s[i + 1]) == string::npos)
                return false;
        }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cout << (Check(s)? "YES": "NO") << "\n";
    return 0;
}