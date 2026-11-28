#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(int n, const vector<int>& seq, set<int>& rows, const vector<string>& S) {
    if (n + 1 == (1 << rows.size())) {
        ll res = 1;
        for (int i = 2; i <= rows.size(); i++)
            res *= i;
        return res;
    }
    int mid = (1 << rows.size() - 1);
    int lef = max(0, (1 << rows.size() - 1)), rig = min(n, (1 << rows.size()) - 1);
    int nd = lef <= rig ? rig - lef + 1 : 0;
    for (auto r : rows) {
        vector<int> nseq;
        for (auto ind : seq)
            if (S[r][ind] == '1')
                nseq.push_back(ind);
        if (nseq.size() == nd)
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> S;
        int cur = n;
        while (cur > 0) {
            string s;
            cin >> s;
            s += '0';
            S.push_back(s);
            cur /= 2;
        }
        set<int> has;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < S.size(); j++)
                val |= (S[j][i] - '0') << j;
            has.insert(val);
        }
        if (has.size() < n + 1) {
            cout << "0\n";
            continue;
        }
        vector<int> seq(n);
        iota(seq.begin(), seq.end(), 0);
        Solve(n, seq, S);
    }
    return 0;
}
