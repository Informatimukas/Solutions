#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    vector<int> d(n);
    for (auto& x : d) {
        cin >> x;
        sum += x;
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    if (s > t)
        swap(s, t);
    int cur = 0;
    while (s < t)
        cur += d[s++];
    cout << min(cur, sum - cur) << "\n";
    return 0;
}
