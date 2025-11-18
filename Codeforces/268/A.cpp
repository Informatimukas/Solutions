#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> ha(n);
    for (auto& [a, b] : ha)
        cin >> a >> b;
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                res += ha[i].first == ha[j].second;
    cout << res << "\n";
    return 0;
}
