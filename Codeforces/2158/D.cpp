#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Swap(string& s, vector<ii>& res, int lef, int rig) {
    res.emplace_back(lef, rig);
    for (int i = lef; i <= rig; i++)
        s[i] = '0' + (1 - (s[i] - '0'));
}

vector<ii> Solve(string& s) {
    vector<ii> res;
    if (s[0] != s[1]) {
        int p = 2;
        while (p < s.length() && s[1] != s[p])
            p++;
        if (p >= s.length()) {
            Swap(s, res, 2, s.length() - 1);
            Swap(s, res, 1, s.length() - 1);
            if (s[0] == '1')
                Swap(s, res, 0, s.length() - 1);
            return res;
        }
        Swap(s, res, 1, p);
    }
    for (int i = 2; i < s.length(); i++)
        if (s[i] != s[i - 1])
            Swap(s, res, 0, i - 1);
    if (s[s.length() - 1] == '1')
        Swap(s, res, 0, s.length() - 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<ii> res1 = Solve(a), res2 = Solve(b);
        cout << res1.size() + res2.size() << "\n";
        for (auto& [a, b] : res1)
            cout << a + 1 << " " << b + 1 << "\n";
        for (auto& [a, b] : res2 | views::reverse)
            cout << a + 1 << " " << b + 1 << "\n";
    }
    return 0;
}
