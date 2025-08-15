#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    ranges::reverse(s);
    cout << (s == t? "YES" : "NO") << "\n";
    return 0;
}