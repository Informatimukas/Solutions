#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int best = 2000000000, mni;
    for (int i = 1; i + k - 1 <= n; i++) {
        int cand = a[i + k - 1] - a[i - 1];
        if (cand < best) {
            best = cand;
            mni = i;
        }
    }
    cout << mni << "\n";
    return 0;
}
