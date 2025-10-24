#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> rads(n);
    for (auto& x : rads)
        cin >> x;
    ranges::sort(rads, greater());
    int sum = 0;
    for (int i = 0; i < rads.size(); i++)
        sum += rads[i] * rads[i] * (i % 2 ? -1 : 1);
    cout << fixed << setprecision(10) << sum * acos(-1.0l) << "\n";
    return 0;
}
