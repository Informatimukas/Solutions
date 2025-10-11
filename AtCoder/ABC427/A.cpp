#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s.erase(s.begin() + s.size() / 2);
    cout << s << "\n";
    return 0;
}