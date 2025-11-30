#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    array<vector<int>, 3> res;
    if (x == y) {
        res[0] = vector(x, 0);
        res[1] = vector(z, 0);
        res[2] = vector(z, 0);
    } else {
        for (int i = 0; i < 2 * z; i++)
            res[2].push_back(i < z ? 0 : 1);
        for (int i = 0; i < z; i++)
            res[1].push_back(0);
        for (int i = 0; i < x; i++)
            res[0].push_back(0);
        for (int i = 0; i < y - x; i++)
            res[0].push_back(1);
    }
    for (auto& V : res) {
        cout << V.size();
        for (auto& v : V)
            cout << " " << v;
        cout << "\n";
    }
    return 0;
}