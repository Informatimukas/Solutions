#include <bits/stdc++.h>
using namespace std;

const vector dx = {-1, 0, 1, 0, 0};
const vector dy = {0, -1, 0, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < n; j++) {
            bool ok = true;
            for (int d = 0; d < dx.size(); d++)
                if (B[i + dy[d]][j + dx[d]] != '#') {
                    ok = false;
                    break;
                }
            if (ok)
                for (int d = 0; d < dx.size(); d++)
                    B[i + dy[d]][j + dx[d]] = '.';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (B[i][j] == '#') {
                cout << "NO\n";
                return 0;
            }
    cout << "YES\n";
    return 0;
}
