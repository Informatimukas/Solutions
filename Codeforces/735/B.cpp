#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    vector<int> seq(n);
    for (auto& x : seq)
        cin >> x;
    ranges::sort(seq, greater());
    if (n1 > n2)
        swap(n1, n2);
    auto sum1 = accumulate(seq.begin(), seq.begin() + n1, 0ll);
    auto sum2 = accumulate(seq.begin() + n1, seq.begin() + n1 + n2, 0ll);
    cout << fixed << setprecision(10) <<
        static_cast<ld>(sum1) / n1 + static_cast<ld>(sum2) / n2 << "\n";
    return 0;
}
