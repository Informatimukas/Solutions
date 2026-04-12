#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector B(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> B[i][j];
        vector<int> comp(n * m + 1);
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                comp[x] = i;
            }
        ranges::sort(B, [&](const vector<int>& a, const vector<int>& b) {
            return comp[a[0]] < comp[b[0]];
        });
        for (auto& V : B)
            for (int j = 0; j < V.size(); j++)
                cout << V[j] << (j + 1 < V.size() ? ' ' : '\n');
    }
    return 0;
}
