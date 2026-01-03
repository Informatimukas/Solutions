#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> ab(n);
    for (auto& [a, b] : ab)
        cin >> a >> b;
    ranges::sort(ab, [](auto&& a, auto&& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });
    vector<int> seq;
    for (auto& x : ab | views::values) {
        auto it = ranges::lower_bound(seq, x);
        if (it == seq.end())
            seq.push_back(x);
        else *it = x;
    }
    cout << seq.size() << "\n";
    return 0;
}
