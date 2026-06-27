#include <bits/stdc++.h>
using namespace std;

void Solve3(int& n, vector<int>& res) {
    res.insert(res.begin(), {n, n, n - 1, n, n - 1, n - 2, n, n - 2, n - 1, n - 1, n - 2, n - 2});
    n -= 3;
}

void Solve2(int& n, vector<int>& res) {
    res.insert(res.begin(), {n, n - 1, n - 1, n, n - 1, n, n, n - 1});
    n -= 2;
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
        vector<int> res;
        if (n % 2)
            Solve3(n, res);
        while (n > 0)
            Solve2(n, res);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
