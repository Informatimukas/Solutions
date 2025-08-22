#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            if (i % 2 == 0)
                s[i] = s[i] == 'a'? 'b': 'a';
            else s[i] = s[i] == 'z'? 'y': 'z';
        cout << s << '\n';
    }
    return 0;
}