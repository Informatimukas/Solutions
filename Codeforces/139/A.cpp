#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<int, 7> a;
    for (auto& x : a)
        cin >> x;
    for (int i = 0; ; i++) {
        int ind = i % a.size();
        if (a[ind] >= n) {
            cout << ind + 1 << "\n";
            return 0;
        }
        n -= a[ind];
    }
    return 0;
}
