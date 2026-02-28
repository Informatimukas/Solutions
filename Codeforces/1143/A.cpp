#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<vector<int>, 2> seq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        seq[x].push_back(i);
    }
    int res = min(seq[0].back(), seq[1].back()) + 1;
    cout << res << "\n";
    return 0;
}
