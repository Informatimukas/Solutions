#include <bits/stdc++.h>
using namespace std;

using triangle = array<int, 6>;

vector<triangle> collectEven(int n) {
    vector<triangle> res;
    for (int i = 1; i <= 3 * n; i += 2)
        for (int j = 1; j <= 3 * n; j += 3) {
            res.push_back({i, j, i + 1, j, i, j + 1});
            res.push_back({i + 1, j + 1, i + 1, j + 2, i, j + 2});
        }
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
        int tot = 3 * n * n;
        vector<triangle> res;
        if (n % 2) {
            res = collectEven(n - 1);
            tot--;
            for (int i = 1; i < 3 * n; i += 2) {
                res.push_back({i, 3 * n - 2, i + 1, 3 * n - 2, i, 3 * n - 1});
                res.push_back({i + 1, 3 * n - 1, i + 1, 3 * n, i, 3 * n});
            }
            for (int j = 1; j <= 3 * (n - 1); j += 2) {
                res.push_back({3 * n - 2, j, 3 * n - 1, j, 3 * n - 2, j + 1});
                res.push_back({3 * n, j, 3 * n, j + 1, 3 * n - 1, j + 1});
            }
        } else res = collectEven(n);
        assert(res.size() == tot);
        cout << res.size() << "\n";
        for (auto& arr : res)
            for (int i = 0; i < arr.size(); i++)
                cout << arr[i] << (i + 1 < arr.size() ? ' ' : '\n');
    }
    return 0;
}
