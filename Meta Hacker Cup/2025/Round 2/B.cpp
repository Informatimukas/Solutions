#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Solve(int x, const vector<int>& seq, const vector<int>& B) {
    int tk = 0;
    ll has = 0, sum = 0;
    for (int i = 0; i < B.size(); i++)
        sum += B[i];
    for (int i = 0; i < B.size() - x; i++)
        has += B[i];
    for (int i = B.size() - x, j = 0; i < B.size(); i++, j++) {
        has += B[i] - tk;
        ll canTake = min(has, sum / (x - j));
        if (seq[j] > canTake)
            return false;
        has -= seq[j];
        sum -= static_cast<ll>(seq[j]) * (x - j);
        tk += seq[j];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, m;
        cin >> n >> m;
        map<int, int> M;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            M[a]++;
        }
        vector<int> B(m);
        for (auto& x : B)
            cin >> x;
        ranges::sort(B);
        vector<int> seq;
        for (auto& val : M | views::reverse | views::values)
            seq.push_back(val);
        int lef = 1, rig = min(B.size(), seq.size());
        while (lef <= rig) {
            int m = (lef + rig) / 2;
            if (Solve(m, seq, B))
                lef = m + 1;
            else rig = m - 1;
        }
        int res = 0;
        for (int i = 0; i < rig; i++)
            res += seq[i];
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}