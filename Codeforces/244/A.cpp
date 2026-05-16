#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> my(k);
    set<int> taken;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        taken.insert(a);
        my[i].push_back(a);
    }
    int pnt = 0;
    for (int i = 1; i <= n * k; i++)
        if (!taken.contains(i)) {
            my[pnt].push_back(i);
            pnt = (pnt + 1) % k;
        }
    for (auto& V : my)
        for (int i = 0; i < V.size(); i++)
            cout << V[i] << (i + 1 < V.size() ? ' ' : '\n');
    return 0;
}
