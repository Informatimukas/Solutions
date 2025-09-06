#include <bits/stdc++.h>
using namespace std;

using interval = array<int, 4>;

vector<int> Solve(const vector<interval>& seq) {
    vector<int> res;
    for (int i = 0, j; i < seq.size(); i = j) {
        j = i + 1;
        int nd = seq[i][2];
        while (j < seq.size() && seq[j - 1][1] > seq[j][0]) {
            if (seq[j][1] < seq[j - 1][1] || seq[j][2] != nd)
                return {};
            j++;
        }
        if (nd == 0)
            for (int z = j - 1; z >= i; z--)
                res.push_back(seq[z][3]);
        else for (int z = i; z < j; z++)
            res.push_back(seq[z][3]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<interval> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i][0] >> seq[i][1];
        seq[i][3] = i + 1;
        if (seq[i][0] > seq[i][1]) {
            seq[i][2] = 1;
            swap(seq[i][0], seq[i][1]);
        } else seq[i][2] = 0;
    }
    ranges::sort(seq);
    auto res = Solve(seq);
    if (res.empty()) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    return 0;
}
