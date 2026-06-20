#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> H(n), L(n);
    for (int i = 0; i < n; i++)
        cin >> H[i] >> L[i];
    for (int i = n - 2; i >= 0; i--)
        H[i] = max(H[i], H[i + 1]);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int lef = 0, rig = n - 1;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (t < L[mid])
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << H[lef] << "\n";
    }
    return 0;
}
