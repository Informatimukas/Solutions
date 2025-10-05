#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Get(const vector<int>& seq) {
    if (seq.empty())
        return numeric_limits<ll>::max();
    ll res = 0;
    int md = seq.size() / 2;
    for (int i = md + 1; i < seq.size(); i++)
        res += seq[i] - (seq[md] + i - md);
    for (int i = md - 1; i >= 0; i--)
        res += seq[md] - (md - i) - seq[i];
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
        string s;
        cin >> s;
        array<vector<int>, 2> seq{};
        for (int i = 0; i < s.length(); i++)
            seq[s[i] - 'a'].push_back(i);
        cout << min(Get(seq[0]), Get(seq[1])) << "\n";
    }
    return 0;
}