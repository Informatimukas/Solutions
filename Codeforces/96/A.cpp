#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j])
            j++;
        if (j - i >= 7) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}