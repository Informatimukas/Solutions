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
    vector ways(B.size(), vector(B[0].length(), 0ll));
    for (int i = 0; i < B.size(); i++)
        for (int j = 0; j < B[i].length(); j++)
            if (B[i][j] == 'S')
                ways[i][j] = 1;
    for (int i = 1; i < B.size(); i++)
        for (int j = 0; j < B[i].size(); j++)
            if (ways[i - 1][j] > 0) {
                if (B[i][j] == '^') {
                    if (j)
                        ways[i][j - 1] += ways[i - 1][j];
                    if (j + 1 < B[i].size())
                        ways[i][j + 1] += ways[i - 1][j];
                } else ways[i][j] += ways[i - 1][j];
            }
    cout << accumulate(ways.back().begin(), ways.back().end(), 0ll) << "\n";
    return 0;
}