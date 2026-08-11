#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> seq(4);
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++) {
        int num = (b[i] - '0') << 1 | (a[i] - '0');
        seq[num].push_back(i);
    }
    array<int, 4> p{};
    for (p[1] = 0; p[1] <= seq[1].size(); p[1]++)
        for (p[3] = 0; p[3] <= seq[3].size(); p[3]++) {
            p[2] = seq[2].size() + seq[3].size() - 2 * p[3] - p[1];
            p[0] = n / 2 - p[1] - p[2] - p[3];
            bool ok = true;
            for (int i = 0; i < p.size(); i++)
                if (p[i] < 0 || p[i] > seq[i].size()) {
                    ok = false;
                    break;
                }
            if (ok) {
                bool pr = false;
                for (int i = 0; i < p.size(); i++)
                    for (int j = 0; j < p[i]; j++) {
                        if (pr) cout << " ";
                        else pr = true;
                        cout << seq[i][j] + 1;
                    }
                cout << "\n";
                return 0;
            }
        }
    cout << "-1\n";
    return 0;
}
