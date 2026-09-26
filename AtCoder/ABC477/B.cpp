#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<int> X(n);
    for (auto& x : X)
        cin >> x;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++)
            if (j != i && abs(X[i] - X[j]) < d) {
                ok = false;
                break;
            }
        if (ok)
            res.push_back(i);
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] + 1 << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
