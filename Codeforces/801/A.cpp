#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i + 1 < s.length(); i++)
        if (s[i] == 'V' && s[i + 1] == 'K') {
            res++;
            s[i] = s[i + 1] = '?';
        }
    int got = 0;
    for (int i = 0; i + 1 < s.length(); i++)
        if (s[i] != '?' && s[i + 1] != '?' && (s[i] == 'V' || s[i + 1] == 'K'))
            got = 1;
    res += got;
    cout << res << "\n";
    return 0;
}
