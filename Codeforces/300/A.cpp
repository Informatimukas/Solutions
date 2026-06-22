#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<vector<int>, 3> res{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0)
            res[0].push_back(a);
        else if (a > 0)
            res[1].push_back(a);
        else res[2].push_back(a);
    }
    if (res[1].empty()) {
        res[1].push_back(res[0].back());
        res[0].pop_back();
        res[1].push_back(res[0].back());
        res[0].pop_back();
    }
    if (res[0].size() % 2 == 0) {
        res[2].push_back(res[0].back());
        res[0].pop_back();
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].size();
        for (auto x : res[i])
            cout << " " << x;
        cout << "\n";
    }
    return 0;
}
