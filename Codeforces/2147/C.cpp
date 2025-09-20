#include <bits/stdc++.h>
using namespace std;

bool Set(int v, int c, const vector<vector<int>>& neigh, vector<int>& col) {
    if (col[v])
        return col[v] == c;
    col[v] = c;
    for (auto& u : neigh[v])
        if (!Set(u, -c, neigh, col))
            return false;
    return true;
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
        string s;
        cin >> s;
        vector neigh(n, vector<int>());
        vector col(n, 0);
        vector<int> left, right;
        for (int i = 0; i < n; )
            if (s[i] == '0') i++;
            else {
                int j = i;
                while (j < n && s[i] == s[j])
                    j++;
                if (j - i == 1 && i > 0 && j < n) {
                    neigh[i - 1].push_back(j);
                    neigh[j].push_back(i - 1);
                } else {
                    if (i > 0)
                        left.push_back(i - 1);
                    if (j < n)
                        right.push_back(j);
                }
                i = j;
            }
        bool ok = true;
        for (int i = 0; i < left.size() && ok; i++)
            ok = Set(left[i], -1, neigh, col);
        for (int i = 0; i < right.size() && ok; i++)
            ok = Set(right[i], 1, neigh, col);
        for (int i = 0; i < n && ok; i++)
            if (s[i] == '0' && !col[i])
                ok = Set(i, -1, neigh, col);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
