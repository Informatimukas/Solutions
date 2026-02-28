#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << (m <= (n + 1) / 2 ? "Yes" : "No") << "\n";
    return 0;
}
