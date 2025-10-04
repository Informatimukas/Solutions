#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, int> M;
    string s;
    cin >> s;
    for (auto& ch : s)
        M[ch]++;
    for (auto& [key, val] : M)
        if (val == 1) {
            cout << key << "\n";
            break;
        }
    return 0;
}
