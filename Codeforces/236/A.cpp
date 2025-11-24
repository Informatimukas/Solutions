#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<char> S;
    string s;
    cin >> s;
    for (auto& x : s)
        S.insert(x);
    if (S.size() % 2)
        cout << "IGNORE HIM!\n";
    else cout << "CHAT WITH HER!\n";
    return 0;
}