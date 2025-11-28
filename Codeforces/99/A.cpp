#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int f = s.find('.');
    if (s[f - 1] == '9')
        cout << "GOTO Vasilisa.\n";
    else {
        if (s[f + 1] >= '5')
            s[f - 1]++;
        cout << s.substr(0, f) << "\n";
    }
    return 0;
}