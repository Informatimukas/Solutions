#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (auto& x : a) {
        cin >> x;
        sum += x;
    }
    int pnt = 0;
    while (k > 0 && pnt < a.size() && a[pnt] < 0) {
        a[pnt] = -a[pnt];
        sum += 2 * a[pnt];
        pnt++;
        k--;
    }
    if (k % 2)
        sum -= 2 * *ranges::min_element(a);
    cout << sum << "\n";
    return 0;
}
