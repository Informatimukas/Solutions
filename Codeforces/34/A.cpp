#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int best = numeric_limits<int>::max();
    int bi, bj;
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        int cand = abs(a[i] - a[ni]);
        if (cand < best) {
            best = cand;
            bi = i + 1;
            bj = ni + 1;
        }
    }
    cout << bi << " " << bj << "\n";
    return 0;
}
