#include <bits/stdc++.h>
using namespace std;

bool isUnique(const vector<string>& B, int r, int c) {
    for (int i = 0; i < B.size(); i++)
        if (i != r && B[r][c] == B[i][c])
            return false;
    for (int j = 0; j < B[0].size(); j++)
        if (j != c && B[r][c] == B[r][j])
            return false;
    return true;
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isUnique(B, i, j))
                cout << B[i][j];
    cout << "\n";
    return 0;
}
