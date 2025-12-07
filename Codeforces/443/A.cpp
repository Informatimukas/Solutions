#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> S;
    string s;
    getline(cin, s);
    if (s.length() < 3) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i < s.length(); i += 3)
        S.insert(s[i]);
    cout << S.size() << "\n";
    return 0;
}