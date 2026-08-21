#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Solve(int n, int k, int l, const vector<int>& d) {
    ii cur = {0, k};
    for (int i = n; i >= 1; i--) {
        if (d[i] > l)
            return false;
        if (d[i] + k <= l) {
            cur = {0, k};
            continue;
        }
        if (cur.first == 0)
            if (cur.second == 0)
                cur = {1, 1};
            else cur.second--;
        else cur.second++;
        if (cur.first == 0)
            cur.second = min(cur.second, l - d[i]);
        else if (d[i] + cur.second > l)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        cout << (Solve(n, k, l, d) ? "Yes": "No") << "\n";
    }
    return 0;
}
