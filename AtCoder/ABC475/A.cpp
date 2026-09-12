#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << (i + 1 < s.length()? 'o' : '\n');
    return 0;
}
