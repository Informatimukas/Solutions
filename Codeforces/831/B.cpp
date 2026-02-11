#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, char> M;
    for (char a = '0'; a <= '9'; ++a)
        M[a] = a;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        M[s1[i]] = s2[i];
        M[toupper(s1[i])] = toupper(s2[i]);
    }
    string s;
    cin >> s;
    for (auto& ch : s)
        ch = M[ch];
    cout << s << "\n";
    return 0;
}
