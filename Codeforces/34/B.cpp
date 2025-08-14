#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> seq;
    while (n--) {
        int x;
        cin >> x;
        if (x < 0)
            seq.push_back(-x);
    }
    ranges::sort(seq);
    int res = 0;
    for (int i = static_cast<int>(seq.size()) - 1; i >= 0 && seq.size() - i <= m; i--)
        res += seq[i];
    cout << res << "\n";
    return 0;
}
