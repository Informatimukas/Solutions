#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
ll x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> x;
    vector<int> A(n);
    for (auto& a : A)
        cin >> a;
    ranges::sort(A, greater());
    int lef = n - k + 1, rig = n;
    while (lef <= rig) {
        int mid = (lef + rig) / 2;
        int good = mid - (n - k);
        ll got = 0;
        for (int i = 0; i < good; i++)
            got += A[i + n - k];
        if (got >= x)
            rig = mid - 1;
        else lef = mid + 1;
    }
    if (lef > n)
        lef = -1;
    cout << lef << "\n";
    return 0;
}
