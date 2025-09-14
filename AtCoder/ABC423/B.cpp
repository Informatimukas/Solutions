#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i];
    int a = 0;
    while (a < n && V[a + 1] == 0)
        a++;
    int b = n;
    while (b > 0 && V[b] == 0)
        b--;
    cout << max(0, b - a - 1) << "\n";
    return 0;
}