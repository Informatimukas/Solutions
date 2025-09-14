#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int lef = r, rig = r;
    for (int i = 1; i <= n; i++)
        if (!a[i]) {
            lef = min(lef, i - 1);
            rig = max(rig, i);
        }
    int res = rig - lef;
    for (int i = lef + 1; i <= rig; i++)
        if (a[i]) res++;
    cout << res << "\n";
    return 0;
}
