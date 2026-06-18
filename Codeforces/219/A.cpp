#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    string s;
    cin >> k >> s;
    vector freq(Maxl, 0);
    for (auto& ch : s)
        freq[ch - 'a']++;
    string cur;
    for (int i = 0; i < Maxl; i++) {
        if (freq[i] % k) {
            cout << "-1\n";
            return 0;
        }
        for (int j = 0; j < freq[i] / k; j++)
            cur += 'a' + i;
    }
    s = "";
    for (int i = 0; i < k; i++)
        s += cur;
    cout << s << "\n";
    return 0;
}
