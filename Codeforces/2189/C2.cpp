#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& a) {
    set<int> S;
    S.insert(a.back());
    for (int i = a.size() - 2; i > 0; i--) {
        S.insert(a[i]);
        if (!S.contains(a[i] ^ i))
            return false;
    }
    return true;
}

vector<int> Solve(int n) {
    vector<int> seq(n + 1);
    iota(seq.begin(), seq.end(), 0);
    do {
        if (Check(seq))
            return seq;
    } while (next_permutation(seq.begin() + 1, seq.end()));
    return {-1};
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
        auto res = Solve(n);
        if (res[0] == -1)
            cout << "-1\n";
        else for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
