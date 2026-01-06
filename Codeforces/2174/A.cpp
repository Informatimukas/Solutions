#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

string Solve(const string& s, array<int, 26>& freq) {
    for (auto ch : s)
        if (freq[ch - 'a']-- == 0)
            return "Impossible";
    string res = "";
    int pnt = 0;
    for (int i = 0; i < freq.size(); i++) {
        while (pnt < s.length() && s[pnt] - 'a' <= i)
            res += s[pnt++];
        while (freq[i]--)
            res += 'a' + i;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string t;
        cin >> t;
        array<int, 26> freq{};
        for (auto ch : t)
            freq[ch - 'a']++;
        cout << Solve(s, freq) << "\n";
    }
    return 0;
}
