#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    set<char> S;
    int n;
    cin >> n;
    cin >> s;
    for (auto& ch : s)
        S.insert(tolower(ch));
    cout << (S.size() == 26 ? "YES" : "NO") << "\n";
    return 0;
}