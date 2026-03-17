#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 3> X, Y;
    for (int i = 0; i < 3; i++)
        cin >> X[i] >> Y[i];
    auto cp = Y;
    ranges::sort(cp);
    vector<vector<int>> res;
    auto lef = *ranges::min_element(X);
    auto rig = *ranges::max_element(X);
    if (lef < rig)
        res.push_back({lef, cp[1], rig, cp[1]});
    for (int i = 0; i < X.size(); i++)
        if (Y[i] < cp[1])
            res.push_back({X[i], Y[i], X[i], cp[1]});
        else if (Y[i] > cp[1])
            res.push_back({X[i], cp[1], X[i], Y[i]});
    cout << res.size() << "\n";
    for (auto& V : res)
        for (int i = 0; i < V.size(); i++)
            cout << V[i] << (i + 1 < V.size() ? ' ' : '\n');
    return 0;
}
