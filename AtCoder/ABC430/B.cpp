#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    set<vector<string>> S;
    for (int i = 0; i + m <= n; i++)
        for (int j = 0; j + m <= n; j++) {
            vector<string> seq;
            for (int i2 = i; i2 < i + m; i2++) {
                string cur;
                for (int j2 = j; j2 < j + m; j2++)
                    cur += B[i2][j2];
                seq.push_back(cur);
            }
            S.insert(seq);
        }
    cout << S.size() << "\n";
    return 0;
}
