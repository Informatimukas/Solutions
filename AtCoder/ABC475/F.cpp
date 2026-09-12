#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> Rotate(const vector<string>& B) {
    int n = B.size();
    int m = B[0].length();
    vector res(m, string(n, '?'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[j][i] = B[i][j];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    if (n < m) {
        B = Rotate(B);
        swap(n, m);
    }
    ll res = 1;
    for (int j1 = 0; j1 < m; j1++) {
        vector good(n, false);
        int allgood = 0;
        for (int j2 = j1; j2 < m; j2++) {
            for (int i = 0; i < n; i++)
                if (!good[i] && B[i][j2] == '.') {
                    good[i] = true;
                    allgood++;
                }
            int rem = allgood;
            int lef = 0, rig = 0;
            int fir = 0, lst = 0;
            while (true)
                if (lef == 0 || rig == 0 || !good[lst - 1]) {
                    if (lst >= n)
                        break;
                    rem -= good[lst];
                    if (B[lst][j1] == '.')
                        lef++;
                    if (B[lst][j2] == '.')
                        rig++;
                    lst++;
                } else {
                    if (good[fir])
                        res += 1 + rem;
                    if (B[fir][j1] == '.')
                        lef--;
                    if (B[fir][j2] == '.')
                        rig--;
                    fir++;
                }
        }
    }
    cout << res << "\n";
    return 0;
}
