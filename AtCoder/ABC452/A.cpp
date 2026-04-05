#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<ii> S;
    S.insert({1, 7});
    S.insert({3, 3});
    S.insert({5, 5});
    S.insert({7, 7});
    S.insert({9, 9});
    int m, d;
    cin >> m >> d;
    if (S.contains({m, d}))
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
