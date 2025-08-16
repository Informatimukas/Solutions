#include <bits/stdc++.h>
using namespace std;

constexpr string colours = "ROYGBIV";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ind = i < 3? 4 + i: i % 4;
        cout << colours[ind];
    }
    cout << "\n";
    return 0;
}
