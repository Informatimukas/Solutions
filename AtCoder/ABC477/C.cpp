#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<int> seq;
    for (int i = 0; i + t.length() <= s.length(); i++)
        if (s.substr(i, t.length()) == t)
            seq.push_back(i);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        auto it = ranges::lower_bound(seq, l);
        if (it != seq.end() && *it + t.length() <= r + 1)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
