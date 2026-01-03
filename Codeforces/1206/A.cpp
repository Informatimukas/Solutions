#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<vector<int>, 2> seq{};
    for (auto& V : seq) {
        int n;
        cin >> n;
        V.resize(n);
        for (auto& x : V)
            cin >> x;
    }
    cout << *ranges::max_element(seq[0]) << " " << *ranges::max_element(seq[1]) << "\n";
    return 0;
}
