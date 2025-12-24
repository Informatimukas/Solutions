#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
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
        vector B(n, vector<int>(n));
        ii mx = {0, 1};
        for (int i = 2; i <= n * n; i++) {
            int got = Ask(1, i);
            mx = max(mx, {got, i});
        }
        vector<int> dist1(n * n + 1), dist2(n * n + 1);
        vector<int> spec;
        int root = mx.second;
        B[0][0] = root;
        for (int i = 1; i <= n * n; i++) {
            dist1[i] = Ask(root, i);
            if (dist1[i] == n - 1)
                spec.push_back(i);
        }
        mx = {0, spec[0]};
        for (int i = 1; i < spec.size(); i++) {
            int got = Ask(spec[0], spec[i]);
            mx = max(mx, {got, spec[i]});
        }
        int root2 = mx.second;
        for (int i = 1; i <= n * n; i++) {
            dist2[i] = Ask(root2, i);
            int c = (dist1[i] + dist2[i] - (n - 1)) / 2;
            int r = dist1[i] - c;
            B[r][c] = i;
        }
        cout << "!" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << B[i][j] << (j + 1 < n ? " ": "");
            cout << endl;
        }
    }
    return 0;
}
