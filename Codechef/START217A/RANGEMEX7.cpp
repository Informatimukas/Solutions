#include <bits/stdc++.h>
using namespace std;

int Solve(const vector<int>& seq, int k) {
    set S(seq.begin(), seq.end());
    int res = 0;
    while (!S.empty() && *S.begin() <= k) {
        res++;
        S.erase(S.begin());
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
        int n, k;
        cin >> n >> k;
        set<int> S;
        int mx = 0;
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == k) {
                mx = max(mx, Solve(cur, k));
                cur.clear();
            } else cur.push_back(a);
        }
        mx = max(mx, Solve(cur, k));
        cout << k + 1 - mx << "\n";
    }
    return 0;
}
