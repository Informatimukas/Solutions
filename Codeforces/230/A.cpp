#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, n;
    cin >> s >> n;
    vector<ii> seq(n);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    ranges::sort(seq);
    for (auto& [x, y] : seq) {
        if (s <= x) {
            cout << "NO\n";
            return 0;
        }
        s += y;
    }
    cout << "YES\n";
    return 0;
}
