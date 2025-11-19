#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    cout << ranges::count_if(a, [k](int x) {
        int cnt = 0;
        while (x) {
            if (x % 10 == 4 || x % 10 == 7)
                ++cnt;
            x /= 10;
        }
        return cnt <= k;
    }) << "\n";
    return 0;
}
