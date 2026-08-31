#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> seq(n);
    for (auto& x : seq)
        cin >> x;
    int l = 0, r = n - 1;
    int res = 0;
    while (l <= r) {
        if (seq[l] == 0 && seq[r] == 1 || seq[l] == 1 && seq[r] == 0) {
            cout << "-1\n";
            return 0;
        }
        if (seq[l] == 0 || seq[r] == 0) {
            if (seq[l] != 0)
                res += a;
            if (seq[r] != 0)
                res += a;
        } else if (seq[l] == 1 || seq[r] == 1) {
            if (seq[l] != 1)
                res += b;
            if (seq[r] != 1)
                res += b;
        } else {
            res += min(a, b);
            if (l != r)
                res += min(a, b);
        }
        l++;
        r--;
    }
    cout << res << "\n";
    return 0;
}
