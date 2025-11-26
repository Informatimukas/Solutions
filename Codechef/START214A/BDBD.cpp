#include <bits/stdc++.h>
using namespace std;

int Prev(const string& s, int k) { return (k + static_cast<int>(s.length()) - 1) % s.length(); }

int Next(const string& s, int k) { return (k + 1) % s.length(); }

void Solve(const string& s, int k) {
    k--;
    if (s[k] != '1') {
        cout << "-1\n";
        return;
    }
    vector ans = {k};
    int l = Prev(s, k);
    int r = Next(s, k);
    if (s[l] == '0') {
        ans.push_back(l);
        l = Prev(s, l);
    } else if (s[r] == '0') {
        ans.push_back(r);
        r = Next(s, r);
    } else {
        cout << "-1\n";
        return;
    }
    for (int i = 2; i + 1 < s.length(); i += 2) {
        if (s[l] > s[r]) {
            ans.push_back(l);
            ans.push_back(r);
        } else {
            ans.push_back(r);
            ans.push_back(l);
        }
        l = Prev(s, l);
        r = Next(s, r);
    }
    if (s.length() % 2)
        ans.push_back(l);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << (i + 1 < ans.size() ? ' ' : '\n');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        Solve(s, k);
    }
    return 0;
}
