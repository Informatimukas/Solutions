#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n + 1);
    for (auto& x : a)
        cin >> x;
    for (int i = 1; i < a.size() && k > 0; i += 2)
        if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1]) {
            a[i]--;
            k--;
        }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    return 0;
}
