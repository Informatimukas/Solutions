#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> res;
    int mn = 1000000007;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < mn) {
            mn = a;
            res.clear();
        }
        if (mn == a)
            res.push_back(i + 1);
    }
    if (res.size() == 1)
        cout << res.back() << "\n";
    else cout << "Still Rozdil\n";
    return 0;
}
