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
    int mn = *ranges::min_element(a);
    for (auto x : a)
        if (x % mn) {
            cout << "-1\n";
            return 0;
        }
    cout << mn << "\n";
    return 0;
}
