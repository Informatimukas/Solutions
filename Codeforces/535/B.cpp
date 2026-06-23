#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll lim = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> seq = {4, 7};
    for (int i = 0; i < seq.size() && seq[i] <= lim; i++)
        for (auto el : {4, 7})
            seq.push_back(10 * seq[i] + el);
    int n;
    cin >> n;
    cout << distance(seq.begin(), ranges::lower_bound(seq, n)) + 1 << "\n";
    return 0;
}
