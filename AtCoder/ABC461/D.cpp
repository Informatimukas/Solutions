#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(const vector<string>& B, int k) {
    ll res = 0;
    vector<int> sum(B.size());
    for (int j1 = 0; j1 < B[0].length(); j1++) {
        ranges::fill(sum, 0);
        for (int j2 = j1; j2 < B[0].length(); j2++) {
            int lst = 0, cur = 0;
            for (int i = 0; i < B.size(); i++) {
                sum[i] += B[i][j2] - '0';
                cur += sum[i];
                while (lst <= i && cur > k)
                    cur -= sum[lst++];
                res += i - lst + 1;
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> B(h);
    for (auto& x : B)
        cin >> x;
    cout << Solve(B, k) - Solve(B, k - 1) << "\n";
    return 0;
}
