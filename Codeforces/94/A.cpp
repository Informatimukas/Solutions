#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string password;
    cin >> password;
    map<string, int> M;
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        M.emplace(s, i);
    }
    for (int i = 0; i < password.length(); i += 10)
        cout << M[password.substr(i, 10)];
    cout << "\n";
    return 0;
}