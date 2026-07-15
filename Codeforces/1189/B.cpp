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
    ranges::sort(a, greater());
    if (a[0] >= a[1] + a[2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    a.insert(a.end(), a[1]);
    a.erase(a.begin() + 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    return 0;
}
