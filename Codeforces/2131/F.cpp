#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> Get(const string& s) {
    vector<int> seq;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        cur += s[i] == '0'? 1: -1;
        seq.push_back(cur);
    }
    ranges::sort(seq);
    return seq;
}

ll Count(const string& s, const vector<int>& seq) {
    ll res = 0;
    int ones = 0, zers = 0, cur = 0;
    for (int i = 0; i < s.length(); i++) {
        cur += s[i] == '0'? 1: -1;
        if (s[i] == '0') zers++;
        else ones++;
        int small = distance(seq.begin(), ranges::lower_bound(seq, -cur));
        res += static_cast<ll>(small) * zers + static_cast<ll>(seq.size() - small) * ones;
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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> seqA = Get(a);
        vector<int> seqB = Get(b);
        cout << Count(a, seqB) + Count(b, seqA) << "\n";
    }
    return 0;
}
