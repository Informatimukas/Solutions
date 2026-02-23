#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<char, int> M;
    string s;
    cin >> s;
    for (auto ch : s)
        M[ch]++;
    for (auto& [key, value] : M)
        if (value > k) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
