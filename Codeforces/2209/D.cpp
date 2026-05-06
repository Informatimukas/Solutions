#include <bits/stdc++.h>
using namespace std;

using ic = pair<int, char>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int r, g, b;
        cin >> r >> g >> b;
        vector<ic> seq = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
        ranges::sort(seq);
        string s;
        while (seq[2].first > 0 && seq[0].first > 0)
        while (seq[0].first > 0) {
            s += string(1, seq[2].second) + string(1, seq[0].second);
            seq[0].first--;
            seq[2].first--;
            if (seq[1].first > seq[2].first)
                swap(seq[1], seq[2]);
        }
        if (s.length() >= 2 && s[s.length() - 2] == seq[2].second)
            swap(seq[1], seq[2]);
        while (seq[1].first > 0 && seq[2].first > 0) {
            s += string(1, seq[1].second) + string(1, seq[2].second);
            seq[1].first--;
            seq[2].first--;
        }
        if (seq[1].first > seq[2].first)
            swap(seq[1], seq[2]);
        if (s.length() < 1 || s.length() < 3 && s[s.length() - 1] != seq[2].second ||
            s[s.length() - 1] != seq[2].second && s[s.length() - 3] != seq[2].second)
            s += seq[2].second;
        cout << s << "\n";
    }
    return 0;
}
