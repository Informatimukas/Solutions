#include <bits/stdc++.h>
using namespace std;

using triangle = array<int, 6>;

void addRectangle(vector<triangle>& res, int r, int c, bool horizontal) {
    if (horizontal) {
        res.push_back({r, c, r, c + 1, r + 1, c});
        res.push_back({r, c + 2, r + 1, c + 2, r + 1, c + 1});
    } else {
        res.push_back({r, c, r, c + 1, r + 1, c});
        res.push_back({r + 1, c + 1, r + 2, c + 1, r + 2, c});
    }
}

vector<triangle> collectEven(int n) {
    vector<triangle> res;
    for (int i = 1; i <= 3 * n; i += 2)
        for (int j = 1; j <= 3 * n; j += 3)
            addRectangle(res, i, j, true);
    return res;
}

vector<triangle> collectOdd(int n) {
    vector<triangle> res;
    for (int i = 1; i <= 3 * n; i += 3)
        for (int j = 1; j <= (i <= 3 * n - 6 ? 3 * n - 3 : 3 * n - 5); j += 2)
            addRectangle(res, i, j, false);
    for (int i = 1; i <= 3 * n - 5; i += 2)
        addRectangle(res, i, 3 * n - 2, true);
    addRectangle(res, 3 * n - 4, 3 * n - 3, false);
    addRectangle(res, 3 * n - 4, 3 * n - 1, false);
    addRectangle(res, 3 * n - 1, 3 * n - 2, true);
    int c = 3 * n - 4;
    int r = 3 * n - 5;
    res.push_back({r, c, r, c + 1, r + 1, c});
    r += 2;
    res.push_back({r, c, r + 2, c + 1, r + 1, c});
    r += 2;
    res.push_back({r, c, r + 1, c + 1, r + 1, c});
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
        if (n == 1) {
            tot--;
            res.push_back({1, 1, 1, 2, 2, 1});
            res.push_back({2, 3, 3, 2, 3, 3});
        } else if (n % 2)
            res = collectOdd(n);
        else res = collectEven(n);
        assert(res.size() == tot);
        cout << res.size() << "\n";
        for (auto& arr : res)
            for (int i = 0; i < arr.size(); i++)
                cout << arr[i] << (i + 1 < arr.size() ? ' ' : '\n');
    }
    return 0;
}
