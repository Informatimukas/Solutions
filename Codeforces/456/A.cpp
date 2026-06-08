#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> seq(n);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    ranges::sort(seq);
    cout << (ranges::adjacent_find(seq, greater(), [](auto&& x) { return x.second; }) != seq.end() ?
        "Happy Alex" : "Poor Alex") << "\n";
    return 0;
}
