#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 1; j < 8; j++)
            if (s[j - 1] == s[j]) {
                cout << "NO\n";
                return 0;
            }
    }
    cout << "YES\n";
    return 0;
}
