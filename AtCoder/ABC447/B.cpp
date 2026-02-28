#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, int> M;
    string s;
    cin >> s;
    for (auto ch : s)
        M[ch]++;
    int mx = 0;
    for (auto x : M | views::values)
        mx = max(mx, x);
    for (auto ch : s)
        if (M[ch] < mx)
            cout << ch;
    cout << "\n";
    return 0;
}
