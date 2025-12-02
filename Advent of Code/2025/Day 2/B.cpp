#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Get(const vector<ll>& seq, const vector<ll>& sums, ll x) {
    auto it = distance(seq.begin(), ranges::upper_bound(seq, x));
    if (it == seq.size())
        exit(1);
    return sums[it];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> seq;
    vector<ll> sums;
    for (int i = 1; i <= 1000000; i++) {
        string s = to_string(i);
        string cur = s;
        while (cur.length() + s.length() <= 13) {
            cur += s;
            seq.push_back(stoll(cur));
        }
    }
    ranges::sort(seq);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    sums.resize(seq.size() + 1);
    for (int i = 0; i < seq.size(); i++)
        sums[i + 1] = sums[i] + seq[i];
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            s[i] = ' ';
    stringstream ss(s);
    ll a, b;
    ll res = 0;
    while (ss >> a >> b) {
        cout << "[" << a << ", " << b << "]\n";
        cout << Get(seq, sums, b) - Get(seq, sums, a - 1) << endl;
        res += Get(seq, sums, b) - Get(seq, sums, a - 1);
    }
    cout << res << endl;
    return 0;
}