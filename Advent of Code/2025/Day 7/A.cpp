#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    string s;
    vector<string> B;
    while (cin >> s)
        B.push_back(s);
    int res = 0;
    for (int i = 1; i < B.size(); i++)
        for (int j = 0; j < B[i].size(); j++)
            if (B[i - 1][j] == 'S') {
                if (B[i][j] == '^') {
                    res++;
                    if (j)
                        B[i][j - 1] = 'S';
                    if (j + 1 < B[i].size())
                        B[i][j + 1] = 'S';
                } else B[i][j] = 'S';
            }
    cout << res << "\n";
    return 0;
}